int freeRam()
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
//7059
void test(int i)
{
	strcpy(bline, "Just Testing");
	strcat(bline, " This out 1");
	myGLCD.print(bline, LEFT, i);
}

void test1(int i)
{
	strcpy(bline,  "Just Testing");
	strcat(bline, " This out 1234 Bigger because I can");
	myGLCD.print(bline, LEFT, i);
}

void test2(int i)
{
	strcpy(bline,  "Just Testing");
	strcat(bline," This out smaller");
	myGLCD.print(bline, LEFT, i);
}

void test3(int i)
{
	strcpy(bline, "Just Testing");
	strcat(bline, " This out 3");
	myGLCD.print(bline, LEFT, i);
}

void test4(int i)
{
	strcpy(bline,  "Just Testing because this is never ever called, I just want to see how much this affects the string function.... ");
	strcat(bline, " This out 3");
	myGLCD.print(bline, LEFT, i);
}

void test5(int i)
{
	strcpy(bline, "Just Testing because this is never ever called, I just want to see how much this affects the string function.... ");
	strcat(bline, " This out 3");
	myGLCD.print(bline, LEFT, i);
}

void test6(int i)
{
	strcpy(bline, "Just Testing because this is never ever called, I just want to see how much this affects the string function.... ");
	strcat(bline, " This out 3");
	myGLCD.print(bline, LEFT, i);
}

void test7(int i)
{
	strcpy(bline, "Just Testing because this is never ever called, I just want to see how much this affects the string function.... ");
	strcat(bline, " This out 3 longer and longer and longer and longer and longer and longer and longer and longer and longer");
	myGLCD.print(bline, LEFT, i);
}