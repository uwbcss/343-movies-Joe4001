#include "command.h"

class Return : public Command {
private:
  int customerId;
  std::string mediaType;
  std::string movieType;
  std::string movieKey;

public:
  Return(int customerId, char mediaType, char movieType,
         const std::string &movieKey);
  void execute(Inventory &inventory, CustomerTable &manager) override;
};

class ReturnFactory : public CommandFactory {
public:
  ReturnFactory();
  Command *makeCommand(const std::string &data) const override;
};