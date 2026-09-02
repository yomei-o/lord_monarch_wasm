/* 1000:0210 */

ulong FUN_1000_0210(void)

{
  byte *pbVar1;
  int iVar2;
  byte in_AL;
  byte bVar3;
  undefined *puVar4;
  undefined1 uVar5;
  int in_DX;
  undefined2 in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  pbVar1 = (byte *)(CONCAT11((char)((uint)in_BX >> 8) + in_AL,(char)in_BX) + unaff_SI);
  *pbVar1 = *pbVar1 & in_AL;
  iVar2 = *(int *)0xe8c;
  out(0x77,0x30);
  puVar4 = (undefined *)&DAT_0000_9fe8;
  if ((*(byte *)0x501 & 0x80) != 0) {
    puVar4 = (undefined *)&DAT_0000_81e8;
  }
  *(undefined2 *)0x3b4a = puVar4;
  out(0x71,(char)puVar4);
  uVar5 = (undefined1)((uint)puVar4 >> 8);
  out(0x71,uVar5);
  bVar3 = in(2);
  out(2,bVar3 & 0xfe);
  return CONCAT22(in_DX - iVar2,CONCAT11(uVar5,bVar3)) & 0xfffffffe;
}


