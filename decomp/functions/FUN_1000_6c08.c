/* 1000:6c08 */

undefined4 __cdecl16near FUN_1000_6c08(undefined2 param_1)

{
  code *pcVar1;
  undefined2 in_AX;
  uint uVar2;
  undefined1 extraout_AH;
  int iVar3;
  byte in_DL;
  uint *puVar4;
  undefined2 unaff_DS;
  
  uVar2 = 0x301;
  puVar4 = (uint *)0xbd8e;
  iVar3 = 8;
  do {
    *puVar4 = CONCAT11(in_DL,in_DL >> 1) & 0x1ff;
    puVar4[1] = uVar2;
    uVar2 = CONCAT11((char)(uVar2 >> 8),(char)uVar2 + '\x01');
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pcVar1 = (code *)swi(0x1b);
  (*pcVar1)();
  *(undefined1 *)0x3e92 = extraout_AH;
  return CONCAT22(in_AX,param_1);
}


