#ifndef RANGE_H
#define RANGE_H

#include "Hand.h"
#include <set>

class Range
{
    struct Comparator{
        bool operator()(const Hand& lhs, const Hand& rhs) const { return lhs < rhs; }
    };
    std::set<Hand, Comparator> rfi_;
    std::set<Hand, Comparator> coldCall_;
    std::set<Hand, Comparator> threeBetBluff_;
    std::set<Hand, Comparator> threeBetValue_;
    std::set<Hand, Comparator> vs3betCall_;
    std::set<Hand, Comparator> vsSqzCall_;
    std::set<Hand, Comparator> fourBetBluff_;
    std::set<Hand, Comparator> fourBetValue_;
    std::set<Hand, Comparator> vs4betCall_;
    std::set<Hand, Comparator> broke_;

public:
    Range(const std::set<Hand, Comparator>& rfi, const std::set<Hand, Comparator>& coldCall, const std::set<Hand, Comparator>& threeBetBluff,
          const std::set<Hand, Comparator>& threeBetValue, const std::set<Hand, Comparator>&  vs3betCall, const std::set<Hand, Comparator>& vsSqzCall,
          const std::set<Hand, Comparator>& fourBetBluff, const std::set<Hand, Comparator>& fourBetValue, const std::set<Hand, Comparator>& vs4betCall,
          const std::set<Hand, Comparator>& broke)
        : rfi_(rfi), coldCall_(coldCall), threeBetBluff_(threeBetBluff), threeBetValue_(threeBetValue), vs3betCall_(vs3betCall),
          vsSqzCall_(vsSqzCall), fourBetBluff_(fourBetBluff), fourBetValue_(fourBetValue), vs4betCall_(vs4betCall), broke_(broke) {}
    bool isInRfi(Hand h) { return rfi_.find(h) != rfi_.end(); }
    bool isInColdCall(Hand h) { return coldCall_.find(h) != coldCall_.end(); }
    bool isInThreeBetBluff(Hand h) { return threeBetBluff_.find(h) != threeBetBluff_.end(); }
    bool isInThreeBetValue(Hand h) { return threeBetValue_.find(h) != threeBetValue_.end(); }
    bool isInVs3betCall(Hand h) { return vs3betCall_.find(h) != vs3betCall_.end(); }
    bool isInVsSqzCall(Hand h) { return vsSqzCall_.find(h) != vsSqzCall_.end(); }
    bool isInFourBetBluff(Hand h) { return fourBetBluff_.find(h) != fourBetBluff_.end(); }
    bool isInFourBetValue(Hand h) { return fourBetValue_.find(h) != fourBetValue_.end(); }
    bool isInVs4batCall(Hand h) { return vs4betCall_.find(h) != vs4betCall_.end(); }
    bool isInBroke(Hand h) { return broke_.find(h) != broke_.end(); }
    virtual ~Range() = default;
};

#endif // RANGE_H
