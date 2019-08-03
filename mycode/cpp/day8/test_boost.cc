#include <iostream> 
#include <boost/version.hpp> 
#include <boost/timer.hpp> 
using namespace std; 
int main() 
{ 
    boost::timer t; 
    cout << "max timespan: " << t.elapsed_max() / 3600 << "h" << endl; 
    cout << "min timespan: " << t.elapsed_min() << "s" << endl; 
    cout << "now time elapsed: " << t.elapsed() << "s" << endl; 
    cout << "boost version" << BOOST_VERSION <<endl; 
    cout << "boost lib version" << BOOST_LIB_VERSION <<endl; 
    return 0; 
} 
