%{
#include"y.tab.h"
%}
%%
[a-zA-Z0-9]   {return ALNUM;}
.             {return SYMBOL;}
\n            {return 0;}
%%
