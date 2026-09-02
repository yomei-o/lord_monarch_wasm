/* 1000:5cfb */

int FUN_1000_5cfb(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar4;
  undefined2 *puVar5;
  int iVar6;
  byte in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 *puVar7;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  byte in_CF;
  int in_stack_00000000;
  byte bVar3;
  
  pbVar1 = (byte *)(in_BX + unaff_SI + 2);
  bVar2 = *pbVar1;
  bVar3 = *pbVar1;
  *pbVar1 = (bVar3 - in_DL) - in_CF;
  *(char *)(in_BX + unaff_SI) =
       (*(char *)(in_BX + unaff_SI) + '0') - (bVar2 < in_DL || (byte)(bVar3 - in_DL) < in_CF);
  bVar2 = *(byte *)0x3482;
  *(byte *)0x3482 = bVar2 ^ 1;
  out(0xa6,bVar2 ^ 1);
  puVar7 = (undefined2 *)0x648c;
  iVar6 = 0x480;
  do {
    LOCK();
    uVar4 = puVar7[0x480];
    puVar7[0x480] = *puVar7;
    UNLOCK();
    puVar5 = puVar7;
    puVar7 = puVar7 + 1;
    *puVar5 = uVar4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return in_stack_00000000 + 1;
}


