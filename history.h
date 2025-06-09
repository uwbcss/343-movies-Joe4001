#include "command.h"

using namespace std;

class History : public Command {
private:
  int customerId;

public:
  explicit History(int customerId);
  void execute(Inventory &inventory, CustomerTable &manager) override;
};

class HistoryFactory : public CommandFactory {
public:
  HistoryFactory();
  Command *makeCommand(const string &data) const override;
};