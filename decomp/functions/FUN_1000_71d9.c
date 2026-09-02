/* 1000:71d9 */

void FUN_1000_71d9(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)0x3c06;
  *(int *)0x3c06 =
       uVar1 * 2 + (uint)((((int)(uVar1 << 1 | (uint)((int)uVar1 < 0)) < 0 ^ uVar1) & 1) != 0);
  return;
}


