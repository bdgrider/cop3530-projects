//#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "PSLL.h"


using namespace cop3530;

static PSLL<int> StaticList;

TEST_CASE( "Testing the default constructor, is_empty (PSLL)", "[PSLL(), is_empty()]" ) {

    PSLL<char> List2;
        REQUIRE(List2.size() == 0);
        REQUIRE(List2.is_empty() == true);
}

TEST_CASE( "Testing the push_back function and verifying with item_at function (PSLL)", "[push_back, item_at]" ) {

    PSLL<int> List;
	
    List.push_back(5);
    List.push_back(3);
    List.push_back(1);
    List.push_back(11);
    List.push_back(15);
    
        REQUIRE( List.item_at(1) == 3 );
        REQUIRE( List.item_at(3) == 11 );
        REQUIRE( List.item_at(0) == 5 );
        REQUIRE( List.item_at(2) == 1 );
        REQUIRE( List.item_at(4) == 15 );
}


TEST_CASE( "Testing copy constructor, item_at() (PSLL)", "[PSLL(PSLL), item_at(n)]" ) {

    PSLL<int> List1;
    
    List1.push_back(7);
    List1.push_back(9);
    List1.push_back(11);
    List1.push_back(13);
    List1.push_back(15);
    List1.push_back(17);
    List1.push_back(19);
  

        REQUIRE(List1.item_at(1)==9);

    PSLL<int> List2(List1);
    int n=List1.size();

        REQUIRE(List2.size()==n);

        for(int i=0; i<n; i++) {
            REQUIRE(List1.item_at(i)==List2.item_at(i));
        }

}

TEST_CASE( "Testing the operator=() and item_at() (PSLL)", "[operator=(), item_at()]" ) {

    PSLL<int> List1;
    
    for(int i=0; i<151; i++) {
        List1.push_back(i);
    }
   
    REQUIRE(List1.item_at(3)==3);
    REQUIRE(List1.item_at(31)==31);
    REQUIRE(List1.item_at(111)==111);
    
    StaticList = List1;
    
    REQUIRE(StaticList.item_at(3)==3);
    REQUIRE(StaticList.item_at(31)==31);
    REQUIRE(StaticList.item_at(111)==111);
   
    StaticList.clear();

}

TEST_CASE("Testing the replace() function for PSLL", "[replace(), size(), clear()]") {
    
    for(int i=0; i<231; i++) {
        StaticList.push_back(i+1);
    }
    
        REQUIRE(StaticList.item_at(200) == 201);
        REQUIRE(StaticList.size() == 231);
    
    int retval = StaticList.replace(45, 200);
    
        REQUIRE(retval == 201);
        REQUIRE(StaticList.item_at(200) == 45);
    
    StaticList.clear();
    
        REQUIRE(StaticList.size() == 0);
        
        StaticList.clear();
    
}

TEST_CASE("Testing the insert function for PSLL by inserting 1 at index 8", "[insert()]") {
    
    for(int i=0; i<12; i++) {
        StaticList.push_back(i+1);
    }
    
    StaticList.insert(1, 8);
    
    REQUIRE(StaticList.item_at(8) == 1);
    REQUIRE(StaticList.item_at(9) == 9);
    
    StaticList.clear();
    
}

TEST_CASE("Testing the push_front function for PSLL , item_at(0) should == 12", "[push_front()]") {
    
     for(int i=0; i<12; i++) {
        StaticList.push_front(i+1);
    }
     
     REQUIRE(StaticList.item_at(0) == 12);
     REQUIRE(StaticList.item_at(11) == 1);
     
     StaticList.clear();
    
}

TEST_CASE("Testing remove for PSLL", "[remove()]") {
    
    for(int i=0; i<160; i++) {
        StaticList.push_back(i);
    }
    
    int retval = StaticList.remove(13);
    
    REQUIRE(retval == 13);
    REQUIRE(StaticList.item_at(13) == 14);
    
     StaticList.clear();
}

TEST_CASE("Testing pop_back() and pop_front() for PSLL", "[pop_back, pop_front]") {
    
    for(int i=0; i<160; i++) {
        StaticList.push_back(i);
    }
    
    int retval_back1 = StaticList.pop_back();
    int retval_front1 = StaticList.pop_front();
    int retval_back2 = StaticList.pop_back();
    int retval_front2 = StaticList.pop_front();
    
    REQUIRE(retval_back1 == 159);
    REQUIRE(retval_back2 == 158);
    
    REQUIRE(retval_front1 == 0);
    REQUIRE(retval_front2 == 1);
    
    StaticList.clear();
    
}

TEST_CASE("Testing the assignment operator for PSLL", "[operator=]") {
    
    for(int i=0; i<161; i++) {
        StaticList.push_back(i);
    }
    
    PSLL<int> List2=StaticList;
    
    REQUIRE(List2.item_at(100)==100);
    REQUIRE(List2.item_at(77)==77);
    
}

bool ints_equal_PSLL( const int& a, const int& b) { //argument for contains()
        return (a == b);
}
 
bool in_list_PSLL( PSLL<int>& list, int c ) {
 
return  list.contains( c, ints_equal_PSLL );
}

TEST_CASE("Testing the contains method for PSLL", "[contains]") {
    
    for(int i=0; i<161; i++) {
        StaticList.push_back(i);
    }
    
    REQUIRE( in_list_PSLL(StaticList, 15) == true);
    REQUIRE( in_list_PSLL(StaticList, 9000) == false);
    
    
   // REQUIRE(StaticList.contains(50, bool equals(int a,int b) {if(a==b) {return true;} else {return false;}}) == true);
    StaticList.clear();
}

TEST_CASE("Testing the print() function for PSLL", "[print()]") {
    
    for(int i=0; i< 161; i++) {
        StaticList.push_back(i);
    }
    
    
    std::ostream& o = std::cout;
    
    o << "{";
        for(int i=0; i<161; i++) {
            o << StaticList.item_at(i) << ", ";
        } 
    o << "}";
    
    std::ostream& retval = StaticList.print(std::cout);
    
    REQUIRE(o == retval);
    
}

TEST_CASE("Constructs a list, destructs it, checks the size and head/tail before and after for PSLL", "[]") {
    
    PSLL<int>* test = new PSLL<int>;
    
   for(int i=0; i<231; i++) {
        test->push_back(i+1);
    }
   
   REQUIRE(test->size() == 231);
   delete test;
    
}



        //==============================================================
        //ITERATOR TESTING      ITERATOR TESTING        ITERATOR TESTING
        //==============================================================


TEST_CASE("Constructs a PSLL list, Creates iterators using ", "[PSLL::PSLL(),  PSLL::PSLL_Iter::PSLL_Iter(), PSLL::begin(), PSLL::PSLL_Iter::operator++() ]") {
    PSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    PSLL<int>::iterator iter = testList.begin();
    
    REQUIRE(*iter == 0);
    for(int i=0; i<57; i++) {
        iter++;
    }
    REQUIRE(*iter == 57);
    
}

TEST_CASE("Constructs a PSLL list, gets one begin iterator and ", "[PSLL::PSLL(),  PSLL::PSLL_Iter::PSLL_Iter(), PSLL::begin(), PSLL::PSLL_Iter::operator++(), PSLL::operator==(), PSLL::operator!=()]") {
    /*test the rest of the operators, etc in here
     */
    PSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    PSLL<int>::iterator iter = testList.begin();
    
    for(int i=0; i<111; i++) {
        ++iter;
    }
    
    REQUIRE(*iter == 111);
    PSLL<int>::iterator iter2 = testList.begin();
    REQUIRE((iter == iter2) == false);
    REQUIRE((iter != iter2) == true);
    
    
}

TEST_CASE("Constructs a CONST PSLL list, Creates const iterators using begin()", "[PSLL::PSLL(),  PSLL::PSLL_Const_Iter::PSLL_Const_Iter(), PSLL::begin(), PSLL::PSLL_Const_Iter::operator++() ]") {
    PSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    const PSLL<int> constTestList(testList);
    
    PSLL<int>::const_iterator iter = constTestList.begin();
    
    REQUIRE(*iter == 0);
    for(int i=0; i<57; i++) {
        iter++;
    }
    REQUIRE(*iter == 57);
    
}


TEST_CASE("Constructs a CONST PSLL list, gets a const iterator by begin(), increments one, gets another at different indices, then test the == and != operators on them", "[PSLL::PSLL(),  PSLL::PSLL_Iter::PSLL_Iter(), PSLL::begin(), PSLL::PSLL_Iter::operator++(), PSLL::PSLL_Iter::operator==(), PSLL::PSLL_Iter::operator!=()]") {
    /*test the rest of the operators, etc in here
     */
    PSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    const PSLL<int> constTestList(testList);
    
    PSLL<int>::const_iterator iter = constTestList.begin();
    
    for(int i=0; i<111; i++) {
        ++iter;
    }
    
    REQUIRE(*iter == 111);
    PSLL<int>::const_iterator iter2 = constTestList.begin();
    REQUIRE((iter == iter2) == false);
    REQUIRE((iter != iter2) == true);
    
}