static int w = 5; /*Storage Class: static, Linkage: internal*/
extern int x; /*static, external*/

static float
func1(int a, int b, int c){
	int c/*错误！与形参冲突*/, d, e = 1; /*none*/
	{
		int d, e, w;
		{
			int b, c, d;
			static int y = 2;
		}
	}
	{
		register int a, d, x;
		extern   int y;
	}
}

static int y;

float
func2(int a){
	extern int y;
	static int z;
}
