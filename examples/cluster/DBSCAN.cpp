//#include "../../src/slowmokit/methods/cluster/DBSCAN/DBSCAN.cpp"
//
//int main() {
//    DBSCAN<double> db(0.6, 4);
//    std::vector<std::vector<double>> x = {
//            {1, 2},
//            {3, 4},
//            {2.5, 4},
//            {1.5, 2.5},
//            {3, 5},
//            {2.8, 4.5},
//            {2.5, 4.5},
//            {1.2, 2.5},
//            {1, 3},
//            {1, 5},
//            {1, 2.5},
//            {5, 6},
//            {4, 3}
//    };
//    std::vector<int> labels = db.fitPredict(x);
//    std::cout << "X  Y  Cluster\n";
//    for(int i = 0; i < x.size(); i++) {
//        std::cout << x[i][0] << "  " << x[i][1] << "  " << labels[i] << "\n";
//    }
//    return 0;
//}