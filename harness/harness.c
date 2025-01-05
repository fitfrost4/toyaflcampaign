#include "parser.h"

__AFL_FUZZ_INIT();

main() {


#ifdef __AFL_HAVE_MANUAL_CONTROL
  __AFL_INIT();
#endif

  unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;  // must be after __AFL_INIT
                                                 // and before __AFL_LOOP!
  //increasing might influence stability
  while (__AFL_LOOP(10000)) {

    int len = __AFL_FUZZ_TESTCASE_LEN;  
    if (len < 10) continue;  // optimization for the function

    parse_content((char *)buf);

  }

  return 0;

}
