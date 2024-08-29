#include "../../include/intx/intx.hpp"
#include <iostream>
#include <cassert>

int main(int argc, char**) {
    intx::uint<256> base =     intx::from_string<intx::uint256>("18092513904333065552493296640790748560207343510000633813116524750123642648575");
    intx::uint<256> exponent = intx::from_string<intx::uint256>("12324738456738276389238478983234243245374678748201173819723401482973801392353");
    intx::uint<256> res = intx::exp(base, exponent); // original
    std::cout << "res (original):       " << intx::to_string(res) << "\n";
    intx::uint<256> res1 = intx::exp1(base, exponent); // karatsuba sq
    std::cout << "res1 (karatsuba sq):  " << intx::to_string(res1) << "\n"; 
    intx::uint<256> res2 = intx::exp2(base, exponent); // karatsuba mul
    std::cout << "res2 (karatsuba mul): " << intx::to_string(res2) << "\n"; 
    intx::uint<256> res3 = intx::exp3(base, exponent); // toomcook3 sq
    std::cout << "res3 (toomcook3 sq):  " << intx::to_string(res3) << "\n"; 
    intx::uint<256> res4 = intx::exp4(base, exponent); // toomcook3 mul
    std::cout << "res4 (toomcook3 mul): " << intx::to_string(res4) << "\n"; 
    return 0;
}