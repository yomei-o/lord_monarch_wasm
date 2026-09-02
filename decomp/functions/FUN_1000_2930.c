/* 1000:2930 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_2930(void)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined2 in_AX;
  byte bVar5;
  char in_CL;
  byte bVar6;
  undefined2 in_DX;
  int in_BX;
  int iVar7;
  int unaff_BP;
  int unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iStack0002;
  undefined4 in_stack_00000001;
  
  bVar6 = (byte)in_DX;
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | bVar6;
  pbVar2 = (byte *)(in_BX + unaff_SI + 0x443a);
  bVar5 = (byte)((uint)in_AX >> 8);
  *pbVar2 = *pbVar2 | bVar5;
  uVar4 = (undefined1)in_AX;
  *(undefined1 *)0x1010 = uVar4;
  pbVar2 = (byte *)(unaff_BP + unaff_SI + 0x443a);
  *pbVar2 = *pbVar2 | bVar5;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + '\x01';
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_CL;
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + '\x01';
  bVar3 = *(byte *)(in_BX + unaff_SI);
  *(char *)(in_BX + unaff_SI) =
       *(char *)(in_BX + unaff_SI) + in_CL + CARRY1(bVar5,*(byte *)(in_BX + unaff_SI));
  iVar7 = CONCAT11((char)((uint)in_BX >> 8) + *(char *)(unaff_BP + unaff_SI),(byte)in_BX);
  iStack0002 = (int)((ulong)in_stack_00000001 >> 8);
  *(char *)(iVar7 + iStack0002) = *(char *)(iVar7 + iStack0002) - bVar6;
  *(byte *)(unaff_BP + 0x3a) = *(byte *)(unaff_BP + 0x3a) | (byte)in_BX;
  *(byte *)(iVar7 + iStack0002) = *(byte *)(iVar7 + iStack0002) ^ bVar6;
  *unaff_DI = uVar4;
  unaff_DI[1] = uVar4;
  pbVar2 = (byte *)(iVar7 + iStack0002 + 0x3a);
  *pbVar2 = *pbVar2 | bVar5 + bVar3;
  pcVar1 = (char *)(unaff_BP + iStack0002 + 0x62);
  *pcVar1 = *pcVar1 + (char)((uint)in_DX >> 8);
  return;
}


