/* 1000:0000 */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void entry_1000_0000(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  code *pcVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  undefined2 unaff_CS;
  
  DAT_0000_3c1c = (undefined2)((ulong)uRam0000004c >> 0x10);
  DAT_0000_3c1a = (undefined2)uRam0000004c;
  puVar7 = (undefined1 *)0x1000;
  uRam00000000 = 0x73c;
  uRam00000024 = 0x7e0;
  uRam00000028 = 0x755;
  uRam0000004c = CONCAT22(unaff_CS,0x873);
  uRam00000054 = 0x8b6;
  DAT_0000_3e7e = (undefined2)((ulong)uRam0000006c >> 0x10);
  DAT_0000_3e7c = (undefined2)uRam0000006c;
  DAT_0000_0ffe = 0x5c;
  uRam00000002 = unaff_CS;
  uRam00000026 = unaff_CS;
  uRam0000002a = unaff_CS;
  uRam00000056 = unaff_CS;
  FUN_1000_0187();
  DAT_0000_0ffe = 0x5f;
  FUN_1000_01b9();
  DAT_0000_0ffe = 0x62;
  FUN_1000_024b();
  DAT_0000_32f3 = DAT_0000_0564;
  DAT_0000_32f5 = DAT_0000_056c;
  DAT_0000_3e80 = 0;
  out(0x68,0xb);
  bVar4 = in(2);
  out(2,bVar4 & 0xf9);
  out(0x6a,1);
  out(100,1);
  puVar8 = (undefined2 *)&DAT_0000_249b;
  puVar9 = (undefined2 *)&DAT_0000_3e20;
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar2 = puVar9;
    puVar9 = puVar9 + 1;
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar2 = *puVar1;
  }
  bVar4 = in(0x42);
  if ((bVar4 & 0x10) == 0) {
    DAT_0000_3286 = 1;
  }
  DAT_0000_d274 = 0;
  bVar4 = in(0x31);
  if ((bVar4 & 0x80) == 0) {
    DAT_0000_d274 = 0x4000;
  }
  DAT_0000_280d = DAT_0000_280d | DAT_0000_d274;
  DAT_0000_2811 = DAT_0000_2811 | DAT_0000_d274;
  DAT_0000_0ffe = 0xb4;
  FUN_1000_c6bc();
  DAT_0000_0ffe = 0xb8;
  FUN_1000_06e7();
  DAT_0000_0ffe = 0xbb;
  FUN_1000_7141();
  DAT_0000_c4e8 = DAT_0000_c4e6 * 8;
  puVar8 = (undefined2 *)&DAT_0000_cc00;
  for (iVar5 = 0x34; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar1 = 0;
  }
  DAT_0000_0ffe = 0xda;
  FUN_1000_6c3f();
  DAT_0000_0ffe = 0xdd;
  DAT_0000_3474 = FUN_1000_69df();
  DAT_0000_347c = DAT_0000_3474 ^ 1;
  DAT_0000_0ffe = 0xf8;
  DAT_0000_3476 = DAT_0000_3474;
  DAT_0000_3478 = DAT_0000_3474;
  DAT_0000_347a = DAT_0000_3474;
  FUN_1000_072a();
  DAT_0000_0ffe = 0xfe;
  FUN_1000_072a();
  DAT_0000_3bc6 = 4;
  DAT_0000_0ffe = 0x107;
  FUN_1000_5f7e();
  DAT_0000_0ffe = 0x10a;
  FUN_1000_0ceb();
  DAT_0000_0ffe = 0x10d;
  FUN_1000_e365();
  DAT_0000_0ffe = 0x110;
  FUN_1000_5ca2();
  pcVar3 = (code *)swi(0x1c);
  (*pcVar3)();
  uVar6 = (uint)DAT_0000_3e75;
  do {
    *(undefined2 *)(puVar7 + -2) = 0x120;
    FUN_1000_9a36();
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  *(undefined2 *)(puVar7 + -2) = 0x125;
  FUN_1000_b729();
  *(undefined2 *)(puVar7 + -2) = 0x128;
  FUN_1000_02c3();
  *(undefined2 *)(puVar7 + -2) = 299;
  FUN_1000_bcf4();
  *(undefined2 *)(puVar7 + -2) = 0x12e;
  FUN_1000_026a();
  *(undefined2 *)(puVar7 + -2) = 0x131;
  FUN_1000_02e1();
  *(undefined2 *)(puVar7 + -2) = 0x134;
  FUN_1000_02f9();
  *(undefined2 *)(puVar7 + -2) = 0x137;
  FUN_1000_027c();
  DAT_0000_32bf = 0;
  *(undefined2 *)(puVar7 + -2) = 0x140;
  FUN_1000_0296();
  *(undefined2 *)(puVar7 + -2) = 0x143;
  FUN_1000_a6a5();
  *(undefined2 *)(puVar7 + -2) = 0x146;
  FUN_1000_c946();
  *(undefined2 *)(puVar7 + -2) = 0x149;
  FUN_1000_74c6();
  puVar8 = (undefined2 *)&DAT_0000_249b;
  puVar9 = (undefined2 *)&DAT_0000_3e20;
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar2 = puVar9;
    puVar9 = puVar9 + 1;
    puVar1 = puVar8;
    puVar8 = puVar8 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined2 *)(puVar7 + -2) = 0x157;
  FUN_1000_5cef();
  *(undefined2 *)(puVar7 + -2) = 0x15a;
  FUN_1000_5d0e();
  *(undefined2 *)(puVar7 + -2) = 0x15d;
  FUN_1000_96f2();
  *(undefined2 *)(puVar7 + -2) = 0x160;
  FUN_1000_977e();
  *(undefined2 *)(puVar7 + -2) = 0x163;
  FUN_1000_97a7();
  *(undefined2 *)(puVar7 + -2) = 0x166;
  FUN_1000_9355();
  *(undefined2 *)(puVar7 + -2) = 0x169;
  FUN_1000_727a();
  *(undefined2 *)(puVar7 + -2) = 0x16c;
  FUN_1000_5d0e();
  *(undefined2 *)(puVar7 + -2) = 0x16f;
  FUN_1000_9355();
  *(undefined2 *)(puVar7 + -2) = 0x172;
  FUN_1000_727a();
  *(undefined2 *)(puVar7 + -2) = 0x175;
  FUN_1000_4cdd();
  *(undefined2 *)(puVar7 + -2) = 0x178;
  FUN_1000_054b();
  DAT_0000_3bc6 = 5;
  *(undefined2 *)(puVar7 + -2) = 0x181;
  FUN_1000_5f7e();
  *(undefined2 *)(puVar7 + -2) = 0x184;
  FUN_1000_633b();
  FUN_1000_191c();
  return;
}


