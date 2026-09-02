/* 1000:021d */

uint FUN_1000_021d(void)

{
  undefined1 in_AL;
  undefined1 uVar1;
  undefined *puVar2;
  undefined1 uVar4;
  uint uVar3;
  undefined2 unaff_DS;
  
  out(0x77,in_AL);
  puVar2 = (undefined *)&DAT_0000_9fe8;
  if ((*(byte *)0x501 & 0x80) != 0) {
    puVar2 = (undefined *)&DAT_0000_81e8;
  }
  *(undefined2 *)0x3b4a = puVar2;
  out(0x71,(char)puVar2);
  uVar4 = (undefined1)((uint)puVar2 >> 8);
  out(0x71,uVar4);
  uVar1 = in(2);
  uVar3 = CONCAT11(uVar4,uVar1) & 0xfffe;
  out(2,(char)uVar3);
  return uVar3;
}


