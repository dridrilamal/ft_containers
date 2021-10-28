#include "../utils/utils.hpp"
#include "map.hpp"

template <class key, class mapped>
void    display_map(ft::map<key, mapped> & m)
{
    if (m.empty()) {
        std::cout << "Empty map" << std::endl;
        return ;
    }
    m._rbt.display_sorted();
}

template <class key_type, class mapped_type>
ft::map<key_type, mapped_type>  generate_random_map(int n, int range)
{
    ft::map<key_type, mapped_type>  m;

    for (int i = 0; i < n; i++)
        m.insert(ft::make_pair(rand() % range, rand() % range));
    return (m);
}

int main(void)
{
    srand(time(NULL));
    std::cout << "============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "============" << std::endl << std::endl;

    std::cout << "----- 1. Default constructor -----" << std::endl;
    ft::map<int, int>  m;
    display_map(m);

    for (int i = 0; i < 10 ; i++)
        m.insert(ft::make_pair(rand() % 20, rand() % 20));
    display_map(m);
    
    std::cout << std::endl;
    std::cout << "----- 2. Range constructor -----" << std::endl;

    ft::map<int, int>    range_constructor_map(m.begin(), m.end());
    display_map(range_constructor_map);

    std::cout << std::endl;
    std::cout << "----- 3. Copy constructor -----" << std::endl;

    ft::map<int, int>   copy_constructor_map(range_constructor_map);
    display_map(copy_constructor_map);

    std::cout << std::endl;
    std::cout << "----- 4. Operator = -----" << std::endl;

    ft::map<int, int>   operator_equal_map;
    operator_equal_map = copy_constructor_map;
    display_map(operator_equal_map);

    std::cout << std::endl;
    std::cout << "========" << std::endl;
    std::cout << "CAPACITY" << std::endl;
    std::cout << "========" << std::endl << std::endl;
    
    std::cout << "----- 1. Empty -----" << std::endl;
    ft::map<int, int>   empty_map;
    if (empty_map.empty())
        std::cout << "Empty_map is empty" << std::endl;
    empty_map.insert(ft::make_pair(5,5));
    if (!empty_map.empty())
        std::cout << "Element inserted, map isn't empty" << std::endl;

    std::cout << std::endl;
    std::cout << "----- 2. Size -----" << std::endl;
    std::cout << "empty_map's size: " << empty_map.size() << std::endl;
    std::cout << "constructor's map size: " << m.size() << std::endl;

    std::cout << std::endl;
    std::cout << "----- 3. Max Size -----" << std::endl;
    std::cout << m.max_size() << std::endl;
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "ELEMENT ACCESS" << std::endl;
    std::cout << "==============" << std::endl << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "MODIFIERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "OBSERVERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    std::cout << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << "OPERATIONS" << std::endl;
    std::cout << "==========" << std::endl << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ITERATORS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    ft::map<int, int>   iterators_map = generate_random_map<int, int>(10, 100);
    ft::map<int, int>::iterator it_map_it = iterators_map.begin();
    ft::map<int, int>::iterator it_map_ite = iterators_map.end();
    std::cout << "display map with red black tree function: " << std::endl;
    display_map(iterators_map);
    std::cout << "display map with iterators" << std::endl;
    while (it_map_it != it_map_ite)
    {
        std::cout << "[" << it_map_it->first << ":" << it_map_it->second << "]" << " ";
        ++it_map_it;
    }
    std::cout << std::endl;

    std::cout << "----- Default constructor -----" << std::endl;
    ft::map<int, int>::iterator original_it;
    std::cout << "----- Assignation -----" << std::endl;
    original_it = m.begin();
    std::cout << "----- Copy constructor -----" << std::endl;
    ft::map<int, int>::iterator it(original_it);
    std::cout << "----- Equal comparison -----" << std::endl;
    if (original_it == m.begin() && it == m.begin())
        std::cout << "Default constructor, assignation and copy constructor worked" << std::endl;
    std::cout << "----- Unequal comparison -----" << std::endl;
    ++original_it;
    if (original_it != it)
        std::cout << "Iterators are not equal after incrementation" << std::endl;
    std::cout << "----- * dereferencement -----" << std::endl;
    std::cout << "map used is" << std::endl;
    display_map(m);
    std::cout << "first value: [" << (*it).first << ":" << (*it).second << "]" << std::endl;
    std::cout << "----- -> dereferencement -----" << std::endl;
    std::cout << "first value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Pre increment -----" << std::endl;
    ++it;
    std::cout << "second value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Post increment -----" << std::endl;
    std::cout << "second value(post incr): [" << it->first << ":" << (it++)->second << "]" << std::endl;
    std::cout << "third value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Pre decrement -----" << std::endl;
    --it;
    std::cout << "second value: [" << it->first << ":" << it->second << "]" << std::endl;
    std::cout << "----- Post decrement -----" << std::endl;
    std::cout << "second value: [" << it->first << ":" << (it--)->second << "]" << std::endl;
    std::cout << "first value: [" << it->first << ":" << it->second << "]" << std::endl;
    
    std::cout << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << "REVERSE_ITERATORS" << std::endl;
    std::cout << "=================" << std::endl << std::endl;

    std::cout << "display with red-black tree function" << std::endl;
    display_map(m);
    ft::map<int, int>::reverse_iterator rev_it = m.rbegin();
    ft::map<int, int>::reverse_iterator rev_ite = m.rend();
    std::cout << "display with reverse iterators" << std::endl;
    while (rev_it != rev_ite)
    {
        std::cout << "[" << (*rev_it).first << ":" << (*rev_it).second << "]" << " ";
        ++rev_it;
    }
    std::cout << std::endl;
}

// int main(void)
// {
//     ft::map<char, int>  m;

//     m.insert(ft::make_pair('z', 4));
//     m.insert(ft::make_pair('z', 10));
//     m.insert(ft::make_pair('h', 3));
//     m.insert(ft::make_pair('a', 1));

//     ft::map<char, int>::iterator    it = m.begin();
//     std::cout << it->first << ", " << it->second << std::endl;
//     ++it;
//     std::cout << it->first << ", " << it->second << std::endl;
//     ++it;
//     std::cout << it->first << ", " << it->second << std::endl;

//     return (0);
// }