#include <memory>

class Strategy {
public:
	virtual int execute() = 0;
	virtual ~Strategy() = default;
};

class Context {
private:
	std::unique_ptr<Strategy> strategy;
public:
	void setStrategy(std::unique_ptr<Strategy> new_strategy);
	int executeStrategy();
};

class BasicStrategy : public Strategy {
public:
	int execute() override;
};

class J1losingStrategy : public Strategy {
public:
	int execute() override;
};

class J2losingStrategy : public Strategy {
public:
	int execute() override;
};