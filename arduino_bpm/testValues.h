int testValues[] = {1408,
1475,
1402,
1383,
1399,
1423,
1426,
1400,
1342,
1344,
1457,
1572,
1469,
1361,
1328,
1519,
0,
0,
1125,
1520,
1702,
1776,
1840,
1951,
2217,
2583,
2839,
2691,
2134,
1669,
1459,
1422,
1487,
1571,
1594,
1569,
1516,
1472,
1480,
1514,
1535,
1554,
1600,
1649,
1557,
1381,
1456,
1757,
73,
0,
958,
1535,
1681,
1783,
1935,
2103,
2322,
2595,
2811,
2796,
2349,
1903,
1667,
1582,
1515,
1503,
1679,
1648,
1585,
1524,
1527,
1563,
1612,
1645,
1799,
1822,
1648,
1505,
1527,
1842,
187,
0,
1081,
1699,
1846,
1935,
2096,
2277,
2512,
2800,
3017,
3005,
2534,
2083,
1858,
1757,
1678,
1655,
1662,
1718,
1754,
1697,
1697,
1712,
1667,
1641,
1701,
1776,
1699,
1616,
1614,
1760,
1355,
0,
248,
1455,
1833,
1938,
1982,
2045,
2192,
2479,
2853,
3071,
2823,
2235,
1807,
1635,
1621,
1676,
1683,
1698,
1647,
1616,
1622,
1648,
1659,
1660,
1711,
1781,
1710,
1600,
1617,
1763,
1706,
0,
63,
1339,
1805,
1959,
2032,
2100,
2187,
2415,
2770,
3047,
2881,
1794,
2336,
1661,
1579,
1593,
1636,
1712,
1762,
1744,
1675,
1601,
1579,
1619,
1759,
1887,
1806,
1618,
1552,
1643,
1759,
0,
225,
1324,
1695,
1786,
1910,
2064,
2239,
2461,
2734,
2957,
2499,
1963,
1675,
1611,
1644,
1687,
1705,
1683,
1697,
1713,
1702,
1648,
1587,
1609,
1743,
1783,
1664,
1596,
1559,
1770,
635,
0,
910,
1629,
1818,
1856,
1983,
2167,
2391,
2722,
2960,
2768,
2253,
1851,
1639,
1558,
1589,
1678,
1735,
1761,
1727,
1655,
1610,
1630,
1659,
1674,
1664,
1712,
1765,
1677,
1583,
1589,
1729,
1535,
0,
1039,
1606,
1745,
1849,
1984,
2128,
2315,
2559,
2775,
2770,
2370,
1931,
1718,
1607,
1523,
1506,
1535,
1613,
1639,
1567,
1525,
1525,
1595,
1613,
1593,
1535,
1495,
1553,
1676,
1555,
1482,
1520,
1747,
1111,
0,
388,
1391,
1713,
1846,
1905,
1949,
2061,
2310,
2663,
2871,
2625,
2080,
1671,
1498,
1462,
1520,
1597,
1613,
1587,
1523,
1491,
1579,
1442,
1456,
1499,
1525,
1535,
1475,
1436,
1482,
1643,
1712,
1575,
1462,
1424,
1665,
615,
0,
886,
1535,
1680,
1712,
1763,
1909,
2149,
2434,
2675,
2733,
2272,
1798,
1570,
1573,
1598,
1559,
1497,
1469,
1478,
1509,
1522,
1501,
1435,
1383,
1360,
1379,
1423,
1469,
1469,
1435,
1497,
1575,
1509,
1476,
1484,
1649,
1251,
0,
592,
1424,
1680,
1808,
1929,
2026,
2164,
2382,
2559,
2578,
2206,
1819,
1606,
1489,
1449,
1471,
1535,
1598,
1603,
1535,
1479,
1453,
1456,
1511,
1531,
1520,
1488,
1429,
1427,
1523,
1664,
1571,
1488,
1487,
1655,
1135,
0,
922,
1535,
1680,
1726,
1776,
1925,
2113,
2368,
2607,
2650,
2320,
1891,
1680,
1646,
1613,
1567,
1527,
1524,
1573,
1616,
1648,
1527,
1572,
1535,
1467,
1405,
1380,
1415,
1535,
1680,
1648,
1422,
1333,
1434,
1615,
0,
0,
1085,
1470,
1602,
1661,
1796,
1935,
2113,
2331,
2519,
2521,
2171,
1774,
1585,
1434,
1483,
1520,
1513,
1450,
1395,
1370,
1385,
1413,
1424,
1382,
1328,
1310,
1349,
1493,
1586,
1411,
1296,
1354,
1721,
705,
0,
582,
1340,
1567,
1690,
1818,
1937,
2276,
2515,
2650,
2458,
1975,
1665,
1535,
1497,
1428,
1406,
1415,
1459,
1514,
1521,
1482,
1392,
1339,
1318,
1371,
1414,
1423,
1459,
1527,
1485,
1344,
1359,
1489,
1562,
0,
606,
1398,
1566,
1675,
1808,
1998,
2193,
2448,
2691,
2783,
2433,
1949,
1643,
1526,
1438,
1435,
1433,
1473,
1535,
1562,
1525,
1456,
1392,
1405,
1469,
1584,
1535,
1341,
1479,
1635,
0,
0,
947,
1494,
1713,
1813,
1907,
2000,
2179,
2455,
2755,
2768,
2301,
1809,
1520,
1407,
1406,
1482,
1563,
1584,
1535,
1477,
1438,
1431,
1490,
1579,
1690,
1535,
1446,
1409,
1664,
320,
0,
820,
1563,
1724,
1759,
1824,
1963,
2215,
2535,
2811,
2813,
2354,
1843,
1611,
1535,
1535,
1535,
1527,
1502,
1515,
1535,
1565,
1520,
1606,
1695,
1667,
1450,
1472,
1535,
1719,
0,
0,
955,
1559,
1781,
1873,
1931,
1988,
2175,
2511,
2811,
2814,
2304,
1799,
1533,
1459,
1492,
1584,
1625,
1615,
1631,
1535,
1463,
1420,
1497,
1658,
1667,
1502,
1379,
1345,
1649,
10};
