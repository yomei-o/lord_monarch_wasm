/* 1000:8c60 */

int FUN_1000_8c60(void)

{
  char *pcVar1;
  char in_AL;
  int unaff_BP;
  char *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  do {
    pcVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    if (*pcVar1 == '\0') {
      unaff_SI[unaff_BP] = '\0';
      unaff_SI[unaff_BP] = unaff_SI[unaff_BP];
      return -1;
    }
  } while (*pcVar1 != in_AL);
  return (int)unaff_SI - in_stack_00000000;
}


