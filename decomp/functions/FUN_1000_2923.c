/* 1000:2923 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_2923(void)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  undefined4 uVar4;
  char cVar5;
  byte bVar6;
  char in_CL;
  byte bVar7;
  undefined2 in_DX;
  int in_BX;
  int iVar8;
  int unaff_BP;
  undefined4 *unaff_SI;
  char *unaff_DI;
  undefined2 uVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iStack0002;
  undefined4 in_stack_00000001;
  
  uVar4 = *unaff_SI;
  uVar9 = (undefined2)((ulong)uVar4 >> 0x10);
  cVar5 = (char)uVar4;
  bVar6 = (byte)((ulong)uVar4 >> 8);
  if (cVar5 == *(char *)((int)unaff_SI + -0x62)) {
    *(byte *)((int)unaff_SI + -0x62) = bVar6;
  }
  bVar7 = (byte)in_DX;
  *(byte *)(in_BX + (int)unaff_SI) = *(byte *)(in_BX + (int)unaff_SI) | bVar7;
  pbVar2 = (byte *)((int)unaff_SI + in_BX + 0x443a);
  *pbVar2 = *pbVar2 | bVar6;
  *(char *)0x1010 = cVar5;
  pbVar2 = (byte *)((int)unaff_SI + unaff_BP + 0x443a);
  *pbVar2 = *pbVar2 | bVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + '\x01';
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + in_CL;
  *(char *)(unaff_BP + (int)unaff_SI) = *(char *)(unaff_BP + (int)unaff_SI) + '\x01';
  bVar3 = *(byte *)(in_BX + (int)unaff_SI);
  *(char *)(in_BX + (int)unaff_SI) =
       *(char *)(in_BX + (int)unaff_SI) + in_CL + CARRY1(bVar6,*(byte *)(in_BX + (int)unaff_SI));
  iVar8 = CONCAT11((char)((uint)in_BX >> 8) + *(char *)(unaff_BP + (int)unaff_SI),(byte)in_BX);
  iStack0002 = (int)((ulong)in_stack_00000001 >> 8);
  *(char *)(iVar8 + iStack0002) = *(char *)(iVar8 + iStack0002) - bVar7;
  *(byte *)(unaff_BP + 0x3a) = *(byte *)(unaff_BP + 0x3a) | (byte)in_BX;
  *(byte *)(iVar8 + iStack0002) = *(byte *)(iVar8 + iStack0002) ^ bVar7;
  *unaff_DI = cVar5;
  unaff_DI[1] = cVar5;
  pbVar2 = (byte *)(iVar8 + iStack0002 + 0x3a);
  *pbVar2 = *pbVar2 | bVar6 + bVar3;
  pcVar1 = (char *)(unaff_BP + iStack0002 + 0x62);
  *pcVar1 = *pcVar1 + (char)((uint)in_DX >> 8);
  return;
}


