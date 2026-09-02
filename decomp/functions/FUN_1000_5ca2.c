/* 1000:5ca2 */

undefined4 __cdecl16near FUN_1000_5ca2(void)

{
  char cVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_6c3f();
  FUN_1000_687e();
  if (!(bool)in_CF) {
    FUN_1000_6f4b();
    FUN_1000_68a0();
    if (!(bool)in_CF) goto LAB_1000_5ced;
  }
  puVar5 = (undefined1 *)0x5200;
  iVar2 = 0xa0;
  do {
    cVar1 = FUN_1000_72d0();
    puVar4 = (undefined1 *)0x3e50;
    iVar3 = 0x10;
    do {
      puVar6 = puVar5;
      puVar5 = puVar6 + 1;
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (0x7f < (byte)(cVar1 + 1U)) {
      puVar5 = puVar6 + 0x201;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
LAB_1000_5ced:
  return CONCAT22(in_DX,in_AX);
}


