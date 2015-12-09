#ifndef  NET_H
#define  NET_H

#include "Neuron.h"
#include <iostream>
#include <cassert>

namespace ANN
{
    class Net
    {
    public:
        explicit Net(const vector<int>& topology);      
        vector<double> getResults() const;
        double         getRecentAverageError() const { return recentAverageError_; }
        void           feedForward(const vector<double>& inputVals);
        void           backProp(const vector<double>& targetVals);

    private:
        double        error_;
        double        recentAverageError_;
        vector<Layer> layers_;                       // layers_[layerNum][neuronNum]
        static double recentAverageSmoothingFactor_;
    };
}

#endif // NET_H
