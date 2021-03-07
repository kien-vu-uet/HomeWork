#include <iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    string ch[30][6] = {
        { "      *      " ,
         "    *   *    " ,
         "   *     *   " ,
         "   *******   " ,
         "   *     *   " ,
         "   *     *   "  } ,

        { "    ******    " ,
          "    *     *   " ,
          "    ******    " ,
          "    *     *   " ,
          "    *     *   " ,
          "    ******    "  } ,

        { "   *******   " ,
         "  *          "  ,
         "  *          "  ,
         "  *          "  ,
         "  *          "  ,
         "   *******   "  } ,

        {  "    *******    " ,
          "    *      *   "  ,
          "    *      *   "  ,
          "    *      *   "  ,
          "    *      *   "  ,
          "    *******    "  } ,


         { "    *******   " ,
          "    *         "  ,
          "    ******    "  ,
          "    *         "  ,
          "    *         "  ,
          "    *******   "  } ,

        {  "    *******   " ,
          "    *         "  ,
          "    ******    "  ,
          "    *         "  ,
          "    *         "  ,
          "    *         "  } ,

        {  "     ******    " ,
          "    *          "  ,
          "    *   ****   "  ,
          "    *      *   "  ,
          "    *      *   " ,
          "     ******    "  } ,

        {  "    *     *   "  ,
          "    *     *   "  ,
          "    *******   "  ,
          "    *     *   "  ,
          "    *     *   "  ,
          "    *     *   "  },

        {  "    *******   " ,
          "       *      "  ,
          "       *      "  ,
          "       *      "  ,
          "       *      "  ,
          "    *******   "   },

        {  "    *******   "  ,
          "       *      "  ,
          "       *      "  ,
          "       *      "  ,
          "       *      "  ,
          "    ***       "   },

        {  "    *     *   "  ,
          "    *   *     "  ,
          "    * *       "  ,
          "    * *       "  ,
          "    *   *     "  ,
          "    *     *   "   },

        {  "    *         " ,
          "    *         "  ,
          "    *         "  ,
          "    *         "  ,
          "    *         "  ,
          "    *******   "  },

        {  "    *      *   "  ,
          "    * *  * *   "  ,
          "    *  **  *   "  ,
          "    *      *   "  ,
          "    *      *   "  ,
          "    *      *   "   },

        {  "    *     *   "  ,
          "    **    *   "  ,
          "    * *   *   "  ,
          "    *  *  *   "  ,
          "    *   * *   "  ,
          "    *    **   "   },

     { "   ******    " ,
         "  *      *   "  ,
         "  *      *   "  ,
         "  *      *   "  ,
         "  *      *   "  ,
         "   ******    "   },


        {  "    ******    "  ,
          "    *     *   "  ,
          "    ******    "  ,
          "    *         "  ,
          "    *         "  ,
          "    *         "   },

        { "   ******    "  ,
         "  *      *   "  ,
         "  *      *   "  ,
         "  *   *  *   "  ,
         "  *    * *   "  ,
         "   ******    "  },

         { "    ******    " ,
          "    *     *   "  ,
          "    ******    "  ,
          "    * *       "  ,
          "    *   *     "  ,
          "    *     *   "  } ,


       {  "    ****     " ,
         "   *    *    "  ,
         "    *        "  ,
         "       *     "  ,
         "   *     *   "  ,
         "    *****    "  } ,


        {  "  *******   " ,
          "     *      "  ,
          "     *      "  ,
          "     *      "  ,
          "     *      "  ,
          "     *      "   }  ,

        {  "    *      *   "  ,
          "    *      *   "  ,
          "    *      *   "  ,
          "    *      *   "  ,
          "    *      *   "  ,
          "     ******    "  },


        {  "    *       *   "  ,
          "    *       *   "  ,
          "    *       *   "  ,
          "     *     *    "  ,
          "       *  *     "  ,
          "        **      "  } ,

        { "    *     *     *   "  ,
          "    *     *     *   "  ,
          "    *     *     *   "  ,
          "     *    *    *    "  ,
          "      *  * *  *     "  ,
          "        *    *      "  } ,

       { "  *     *   "  ,
         "   *   *    "  ,
         "    * *     "  ,
         "     *      "  ,
         "    * *     "  ,
         "   *   *    "  ,
         "  *     *   "   },

       { "  *     *   "  ,
         "   *   *    "  ,
         "    * *     "  ,
         "     *      "  ,
         "     *      "  ,
         "     *      "  ,
         "     *      "   },

        { "  *******   " ,
         "       *    "  ,
         "      *     "  ,
         "     *      "  ,
         "   *        "  ,
         "  *******   "  }
    };

    for (int j = 0; j < 6; j++){
        for (int i = 0; i < s.length(); i++)
            cout << ch[s[i] - 'A'][j];
        cout << endl ;
    }
    return 0;
}
