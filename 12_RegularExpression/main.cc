//Topic: Regular Expression
// A regular expression is a specific pattern that provides concise and flexible means
// to "match" strings of text, such as particular characters, words or patrterns of characters.

//1. std::regex_match
//2. std::regex_search
//3. smatch
//4. different grammars
//5. sregex_iterator
//6. s_regex_token_iterator
//7. regex_replace

/*
 Regular Expression Grammars:
    ECMAScript
    basic
    extended
    awk
    grep
    egrep
*/

#include <iostream>
#include <regex>

int main(){
  std::string str;
  while(true) {
    std::cin>>str;
    if(str=="q")
      break;
    //std::regex e("abc");                             //1. Match "abc" exactly
    //std::regex e("abc", std::regex_constants::icase);//2. case insensitivity
    //std::regex e("abc.");                            //3. . means any character except newline
    //std::regex e("abc?");                            //4. ? means 0 or 1 preceding character, here 0 or 1 c
    //std::regex e("abc*");                            //5. * means 0 or more preceding character
    //std::regex e("abc+");                            //6. * means 1 or more preceding character
    //std::regex e("ab[cd]*");                         //7. [...] means any character in the square brackets, ab, abc, abd, abcd, abcc ...
    //std::regex e("ab[^cd]*");                        //8. [...] means any character not inside the square brackets
    //std::regex e("ab[cd]{3}");                       //9. {3} means c or d has to appear for exact 3 times
    //std::regex e("ab[cd]{3,}");                      //10. {3.} means c or d has to appear for >= 3 times
    //std::regex e("ab[cd]{3,5}");                     //11. {3.} means c or d has to appear for >= 3 and <=5 times
    //std::regex e("abc|de[fg]");                      //12. | means use either the characters before or after this
    //std::regex e("abc|de[\]fg]");                    //13. \]  means the character of ']'
    //std::regex e("(abc)de+\\1");                     //14. () means grouping, \\1 means the group 1 appears once again
    //std::regex e("(ab)c(de+)\\2\\1");                //15. ab is group 1, de+ is group 2, abcdeedeeab
    //std::regex e("[[:w:]]+@[[:w:]]+\.com");          //16. [[:w:]] word character: digit, number, or underscore, \. means its a '.' character instead of case 3.    
    //auto match = std::regex_match(str,e);            //***Match
    
    //std::regex e("abc.");  //1. seach abc. at anywhere
    //std::regex e("^abc."); //2. search abc. at the beginning
    //std::regex e("abc.$"); //3. search abc. at the end
    //auto match = std::regex_search(str,e);/***/search e in str

    //std::regex e("^abc.+", std::regex_constants::grep);// Use grep grammar for the regex
    //auto match = regex_search(str,e);
    
    //std::cout<<(match? "Matched":"Not  matched")<<std::endl;


    //smatch m;//typedef std::match_result<string>
    //regex e("([[:w:]]+)@([[:w:]]+)\.com");
    //auto found = regex_search(str, e, m);// search str to find sub-strings matching e, and store the result in m
    //for(int i = 0; i<m.size(); ++i) {
    //  std::cout<<"m["<<n<<"]: str()="<<m[n].str()<<std::endl;
    //}
    //std::cout<<"m.prefix().str(): "<<m.prefix().str()<<std::endl;
    //std::cout<<"m.suffix().str(): "<<m.suffix().str()<<std::endl;
    /*
     * <email>boq@yahoo.com<end>
    //m.size() 3
    //m[0] - boq@yahoo.com    - The entire match
    //m[1] - boq              - The substring that matches the first group
    //m[2] - yahoo            - The substring that matches the second group
    //m.prefix <emial>        - Everything before the first matched character
    //m.suffix <end>          - Everything after the last matched character
    */

    //sregex_iterator
    /*std::string str = "boq@yahoo.com; boqian@hotmail.com;; boqian2000@163.com";
    std::regex e("([[:w:]]+)@([[:w:]]+)\.com");
    sregex_iterator pos(str.cbegin(), str.cend(),e);
    sregex_iterator end;//Default ctor defines past-the-end iterator
    for(; pos!=end; ++pos) {
      std::cout<<"Matched: "<<pos->str(0)<<std::endl;
      std::cout<<"user name: "<<pos->str(1)<<std::endl;
      std::cout<<"Domain: "<<pos->str(2)<<std::endl;
      std::cout<<std::endl;
    }*/

    //regex_token_iterator
    /*std::string str = "boq@yahoo.com; boqian@hotmail.com;; boqian2000@163.com";
    std::regex e("([[:w:]]+)@([[:w:]]+)\.com");
    sregex_token_iterator pos(str.cbegin(), str.cend(),e,0); //all matched whole mail addresses
    //sregex_token_iterator pos(str.cbegin(), str.cend(),e,1); //all matched user names
    //sregex_token_iterator pos(str.cbegin(), str.cend(),e,2); //all matched domains
    sregex_token_iterator end;//Default ctor defines past-the-end iterator
    for(; pos!=end; ++pos) {
      std::cout<<"Matched: "<<pos->str(0)<<std::endl;
      std::cout<<std::endl;
    }*/
    
    std::string str = "boq@yahoo.com; boqian@hotmail.com;; boqian2000@163.com";
    std::regex e("([[:w:]]+)@([[:w:]]+)\.com");
    std::cout<<regex_replace(str,e, "$1 is on $2");// group1(user name) will replace $1, group2(domain) will replace $2
    std::cout<<regex_replace(str,e, "$1 is on $2", regex_constants::format_no_copy);// only have whar requested, like it will ignore ; 
    std::cout<<regex_replace(str,e, "$1 is on $2", regex_constants::format_no_copy|regex_constants::format_frist_only);// the second flag menas only the first match is considered as a match



  }
  return 0;
}
