/* 1000:0222 */

uint FUN_1000_0222(void)

{
  undefined1 uVar1;
  undefined *in_AX;
  undefined1 uVar3;
  uint uVar2;
  undefined2 unaff_DS;
  
  if ((*(byte *)0x501 & 0x80) != 0) {
    in_AX = (undefined *)&DAT_0000_81e8;
  }
  *(undefined2 *)0x3b4a = in_AX;
  out(0x71,(char)in_AX);
  uVar3 = (undefined1)((uint)in_AX >> 8);
  out(0x71,uVar3);
  uVar1 = in(2);
  uVar2 = CONCAT11(uVar3,uVar1) & 0xfffe;
  out(2,(char)uVar2);
  return uVar2;
}


