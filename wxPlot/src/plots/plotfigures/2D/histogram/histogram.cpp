#include "histogram.hpp"


void Histogram::setBinCount(const unsigned int binCount) {
	this->binCount = binCount;
}

void Histogram::setData(const std::vector<double>& data1D) {
	// Find maxY from data1D
	findMaxMin1Ddata(data1D, minY, maxY);

	// Swap
	minX = minY;
	maxX = maxY;

	// Create histogram data
	const std::vector<double> yData = createHistogramData(data1D, minY, maxY, binCount);

	// Find minY and maxY from histogram data
	findMaxMin1Ddata(yData, minY, maxY);
}
