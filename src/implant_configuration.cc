#include "implant_configuration.h"
#include "ladder_helper.h"

using namespace ladder_helper;

ImplantConfiguration::ImplantConfiguration()
{
  config_.reserve(13);
  for(size_type i = 0; i != 13; ++i)
    config_.push_back(Implant(0, intToSlot(i), "abi", "shi", "bri", "fad"));
}

double ImplantConfiguration::avgQL() const
{
  double avg = 0;
  int usedImplantCount = 0;
  for(std::vector<Implant>::size_type i = 0; i != config_.size(); ++i){
    if(config_[i].abi() != "abi" && config_[i].ql() > 0 && config_[i].mustRemove()){
      avg += config_[i].ql();
      ++usedImplantCount;
    }
  }
  if(avg == 0 || usedImplantCount == 0)
    return 0;
  return avg/usedImplantCount;
}
