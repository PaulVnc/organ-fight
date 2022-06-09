#include <gtest/gtest.h>
#include <string>
#include "nlohmann/json.hpp"
#include "src/jsonfunction.h"

/* On va tester les fonctions de parsing du Json avec le json présenté ci-dessous*/

const auto partition = R"({
      "label": "test",
      "chiffrage": 4.0,
      "tempo": 100.0,
      "mesures": [
        {
          "id": 1,
          "notes": [
            {
              "beat": 2,
              "tune": "A"
            },
            {
              "beat": 3,
              "tune": "B"
            }
          ]
        },
        {
          "id": 2,
          "notes": {
            "beat": 1,
            "tune": "C"
          }
        }
      ]
    }
    )"_json;

/*Dans un premier temps, on teste que le json est bien formé et qu'on peut bien récupérer les infos label, chiffrage et tempo du json*/

TEST(TestReadJson, TestOpening) {
    std::string label = "test";
    float chiffrage = 4.0;
    float tempo = 100.0;

    EXPECT_EQ(partition["label"], label);
    EXPECT_EQ(partition["chiffrage"], chiffrage);
    EXPECT_EQ(partition["tempo"], tempo);
}

/* Dans un second temps on teste la fonction get_mesures(json) définie dans src/jsonfunction.h 
Cette fonction prend en argument le json d'une partition et en extrait les différentes mesures, elle renvoit un vecteur de struct mesure (définie dans src/jsonfunction.h)
On vérifie, que les mesures ont étés parsées dans le bon ordre et avec les bonnes informations.*/

TEST(TestReadJson, TestReadingMesure) {
    std::vector<mesure> mesures_json = get_mesures(partition);

    auto notes_mes_1 = R"([
            {
              "beat": 2,
              "tune": "A"
            },
            {
              "beat": 3,
              "tune": "B"
            }
          ])"_json;
    auto notes_mes_2 = R"(
          {
            "beat": 1,
            "tune": "C"
          }
         )"_json;
    mesure mes_1(1,notes_mes_1);
    mesure mes_2(2, notes_mes_2);

    EXPECT_EQ(mesures_json[0].id, mes_1.id);
    EXPECT_EQ(mesures_json[0].json, mes_1.json);

    EXPECT_EQ(mesures_json[1].id, mes_2.id);
    EXPECT_EQ(mesures_json[1].json, mes_2.json);
}

/*Dans un dernier temps, on teste la fonction get_tunes(json mesure, id_mesure, chiffrage, tempo) définie dans src/jsonfunction.h
Cette fonction prend en argument le champs json d'une mesure représentant un tableau de json des notes présentes dans la mesure, l'id de la mesure, le chiffrage du morceau et le tempo du morceau,
elle renvoit un vecteur d'objet Tunes, définis dans src/tunes.h qui représentent chacun une note de la partition qu'on lit avec le json.
On vérifie que les tunes ont étés parsées dans le bon ordre et avec les bonnes informations.*/
TEST(TestReadJson, TestReadingTunes) {
    std::vector<mesure> mesures_json = get_mesures(partition);
    std::vector<Tunes> tunes_mes1_json = get_tunes(mesures_json[0].json, 1, 4.0, 100.0);
    std::vector<Tunes> tunes_mes2_json = get_tunes(mesures_json[1].json, 2, 4.0, 100.0);

    Tunes notes_1("A", 2.0, 1, 4.0, 100.0);
    Tunes notes_2("B", 3.0, 1, 4.0, 100.0);
    Tunes notes_3("C", 1.0, 2, 4.0, 100.0);
    

    EXPECT_EQ(tunes_mes1_json[0].get_time(), notes_1.get_time());
    EXPECT_EQ(tunes_mes1_json[0].get_tune(), notes_1.get_tune());

    EXPECT_EQ(tunes_mes1_json[1].get_time(), notes_2.get_time());
    EXPECT_EQ(tunes_mes1_json[1].get_tune(), notes_2.get_tune());

    EXPECT_EQ(tunes_mes2_json[0].get_time(), notes_3.get_time());
    EXPECT_EQ(tunes_mes2_json[0].get_tune(), notes_3.get_tune());
}