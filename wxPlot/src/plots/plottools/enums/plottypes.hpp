#pragma once

/**
 * @brief Enum representing different plot types.
 *
 * This enum defines various plot types that can be used for visualizing data.
 * The available plot types include line plots, scatter plots, bar charts,
 * and histograms, among others. Additional plot types can be added as needed.
 */
typedef enum {
    WXPLOT_TYPE_LINE,                  ///< Line plot, where data points are connected by a line
    WXPLOT_TYPE_SCATTER,               ///< Scatter plot, where each data point is represented by a marker
    WXPLOT_TYPE_LINE_SCATTER,          ///< Combination of line plot and scatter plot
    WXPLOT_TYPE_SPLINE,                ///< Spline plot, where data points are connected by a smooth curve
    WXPLOT_TYPE_SPLINE_SCATTER,        ///< Combination of spline plot and scatter plot
    WXPLOT_TYPE_BAR,                   ///< Bar plot, where data is represented as rectangular bars
    WXPLOT_TYPE_HIST                   ///< Histogram, representing frequency distribution of data

    // Add more plot types here as necessary
} WXPLOT_TYPE;