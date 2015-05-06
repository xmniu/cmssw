#ifndef RecoLocalCalo_HcalRecAlgos_PedestalSub_h
#define RecoLocalCalo_HcalRecAlgos_PedestalSub_h 1

#include <typeinfo>
#include <vector>

class PedestalSub
{
 public:
  enum Method { DoNothing=0, AvgWithThresh=1, AvgWithThresh3=2, AvgWithThresh2=3,AvgWithoutThresh=4, AvgWithThreshNoPedSub=5, Percentile=6 };

  PedestalSub();
  ~PedestalSub();
  
  void init(Method method, int runCond, float threshold, float quantile);
  
  void calculate(const std::vector<double> & inputCharge, const std::vector<double> & inputPedestal, std::vector<double> & corrCharge) const;
  
  double getCorrection(const std::vector<double> & inputCharge, const std::vector<double> & inputPedestal) const;

  
 private:
  Method fMethod;
  float fThreshold;
  float fQuantile;
  float fCondition;
  
};

#endif 
