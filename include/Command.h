#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;  
};

class NewGame : public Command {
public:
    void execute() override;  
};

class Settings : public Command {
public:
    void execute() override;
};

class Tutorial : public Command {
public:
    void execute() override;
};




#endif 
