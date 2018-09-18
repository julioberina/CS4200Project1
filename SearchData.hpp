#ifndef SEARCH_DATA_HPP
#define SEARCH_DATA_HPP

struct SearchData
{
  int depth;
  int searchCostH1;
  long totalTimeH1;
  int searchCostH2;
  long totalTimeH2;

  SearchData(int d, int sCostH1, long tTimeH1, int sCostH2, long tTimeH2)
  {
    depth = d;
    searchCostH1 = sCostH1;
    totalTimeH1 = tTimeH1;
    searchCostH2 = sCostH2;
    totalTimeH2 = tTimeH2;
  }
};

#endif
