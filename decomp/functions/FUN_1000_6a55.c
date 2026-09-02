/* 1000:6a55 */

undefined4 __cdecl16near FUN_1000_6a55(void)

{
  code *pcVar1;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_DS;
  bool bVar2;
  undefined2 in_stack_00000000;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffe;
  bVar2 = false;
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  if (!bVar2) {
    bVar2 = false;
    pcVar1 = (code *)swi(0x1b);
    (*pcVar1)(puVar3);
    *(undefined1 *)0x3e92 = extraout_AH_00;
    if (!bVar2) {
      pcVar1 = (code *)swi(0x1b);
      (*pcVar1)();
      *(undefined1 *)0x3e92 = extraout_AH_01;
    }
  }
  return CONCAT22(in_AX,in_stack_00000000);
}


