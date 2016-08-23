
#ifndef TEXTUTILITY_HPP
#define TEXTUTILITY_HPP

// includes
#include <vector>
#include <string>
#include <sstream>


/** Convert some type into a string.
 * @param T value : value to convert to string
 * @return string result
 */
template <typename T>
std::string to_string(T const & value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

/** Convert string into some type
* @param T value : value to convert to string
* @return string result
*/
template <typename T>
T string_to_type(std::string const & str){
   T value;
   std::stringstream ss(str);
   ss >> value;
   return value;
}

/** Text utility class
 */
class TextUtility {

   public:
   static std::vector<unsigned int> extract_integers(std::string text);
   static std::string &ltrim(std::string &s);
   static std::string &rtrim(std::string &s);
   static std::string &trim(std::string &s);
};


/** Preprocess a string for dyna.
 * @param string s : string to preprocess
 * @return string& s : string with removed comments
 */
inline std::string preprocess_string_dyna(std::string _text){

   size_t pos = _text.find('$');
   if(pos != std::string::npos)
      return _text.substr(0,pos);
   return _text;

}


#endif
