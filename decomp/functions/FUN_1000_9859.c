/* 1000:9859 */

undefined4 __cdecl16near FUN_1000_9859(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  undefined2 in_AX;
  int iVar9;
  undefined2 in_DX;
  int iVar10;
  undefined2 *unaff_SI;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 unaff_DS;
  
  iVar8 = unaff_SI[2];
  iVar10 = unaff_SI[3];
  uVar1 = unaff_SI[1];
  pbVar13 = (byte *)0x0;
  pbVar12 = (byte *)*unaff_SI;
  iVar9 = iVar8;
  pbVar11 = pbVar12;
  do {
    do {
      bVar5 = *pbVar12;
      *pbVar13 = bVar5;
      bVar6 = pbVar12[-0x8000];
      pbVar13[1] = bVar6;
      bVar7 = *pbVar12;
      pbVar13[2] = bVar7;
      pbVar2 = pbVar12;
      pbVar12 = pbVar12 + 1;
      bVar3 = *pbVar2;
      pbVar4 = pbVar13 + 4;
      pbVar13[3] = bVar3;
      pbVar13 = pbVar13 + 5;
      *pbVar4 = ~(bVar3 & bVar5 & bVar6 & bVar7);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pbVar12 = pbVar11 + 0x50;
    iVar10 = iVar10 + -1;
    iVar9 = iVar8;
    pbVar11 = pbVar12;
  } while (iVar10 != 0);
  return CONCAT22(in_DX,in_AX);
}


