/* 1000:8c67 */

int FUN_1000_8c67(void)

{
  char *pcVar1;
  undefined2 in_AX;
  char cVar2;
  int unaff_BP;
  char *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  do {
    cVar2 = (char)((uint)in_AX >> 8);
    if ((char)in_AX == cVar2) {
      return (int)unaff_SI - in_stack_00000000;
    }
    pcVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    in_AX = CONCAT11(cVar2,*pcVar1);
  } while (*pcVar1 != '\0');
  unaff_SI[unaff_BP] = '\0';
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP];
  return -1;
}


