/* 1000:78f3 */

undefined4 __cdecl16near FUN_1000_78f3(void)

{
  int *piVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  int *unaff_SI;
  undefined2 unaff_DS;
  
  while( true ) {
    piVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    if ((char)*piVar1 == '\0') break;
    if (*piVar1 != 0x4081) {
      FUN_1000_9a54();
      FUN_1000_72d0();
      FUN_1000_79a6();
    }
  }
  return CONCAT22(in_DX,in_AX);
}


