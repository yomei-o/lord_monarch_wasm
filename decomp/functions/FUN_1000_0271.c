/* 1000:0271 */

undefined2 FUN_1000_0271(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  puVar2 = (undefined1 *)0xc800;
  iVar1 = 0x40;
  do {
    *puVar2 = 0x80;
    puVar2[0xb] = 0xff;
    puVar2 = puVar2 + 0x10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return in_stack_00000000;
}


