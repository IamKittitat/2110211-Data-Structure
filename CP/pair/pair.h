#ifndef CP_PAIR
#define CP_PAIR

#include <iostream>

namespace CP{
    template<typename T1, typename T2>
    class pair{
        public:
            T1 first;
            T2 second;

            // Default Constructor
            pair(): first(),second(){}

            // Custom Constructor
            pair(const T1 &a, const T2 &b): first(a),second(b){}

            // Equality Operator
            bool operator==(const pair<T1,T2> &other){
                return (this->first == other.first) && (this->second == other.second);
            }

            // Less than Operator
            bool operator<(const pair<T1,T2> &other) const {
                if(this->first != other.first) return this->first < other.first;
                return this->second < other.second;
            }

            bool operator!=(const pair<T1,T2> &other) const{
                return (this->first != other.first) || (this->second != other.second);
            }

            bool operator>=(const pair<T1,T2> &other) const{
                if(this->first != other.first) return this->first >= other.first;
                return this->second >= other.second;
            }

            /*
            // HW1 : Compare Second before First
            bool operator<(const pair<T1,T2> &other) const {
                if(this->second != other.second) return this->second < other.second;
                return this->first < other.first;
            }
            */

            /*
            // HW2 : sort max to min
            bool operator<(const pair<T1,T2> &other) const{
                if(this->first != other.first) return other.first < this->first;
                return other.second < this->second;
            }
            */

    };
}
#endif // CP_PAIR
