#include <iostream>
#include <string>
#include <mysql++.h>
#include <mysql.h>
#include <thread>
#include <chrono>

#define dbname "reactor"
#define server "localhost"
#define user "root"
#define pass "password"

using namespace std;
using namespace mysqlpp;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Connection con(true);
    try {
        con.connect(dbname, server, user, pass);
        cout << "Connected to database\n";
        string s = "SELECT * FROM users";
        Query q = con.query(s);
        StoreQueryResult sq = q.store();
        StoreQueryResult::iterator it;
        it = sq.begin();
        while (it != sq.end()) {
            Row row = *it;
            cout << row[5] << "\t" << row[6] << "\t" << row[7] << endl;
            it++;
        }
    } catch (Exception &e) {
        cout << e.what() << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    return 0;
}