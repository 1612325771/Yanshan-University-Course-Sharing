﻿/*
Duosi Principles of Computer Composition Virtual Experiment System ,DS-VLAB v1.0
Copyright(C)2013 ZHANG Wen-fen, Email: yydzhwf@163.com  Address: Xiangnan University, Chenzhou Hunan, China
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.

多思计算机组成原理网络虚拟实验系统, DS-VLAB v1.0 
版权所有(C) 张雯雰, 电子邮箱: yydzhwf@163.com
本程序为自由软件；您可依据自由软件基金会所发表的GNU GENERAL PUBLIC LICENSE，对本程序再次发布和/或修改。

作者：湘南学院软件与通信工程学院张雯雰老师
*/



function CompoBUS() {
    this.id;    //此器件div的id与此id相同
    this.type = "i";  //source:数据源器件   intermediate:中间器件   destination:目的器件
    this.name = "BUS";
    this.width = 1075;
    this.height = 30;
    this.image = "";
    this.paddingLR = 5;    //paddingLR：芯片左右边距  
    this.pinName = new Array("A7","A6","A5","A4","A3","A2","A1","A0","B7","B6","B5","B4","B3","B2","B1","B0","C7","C6","C5","C4","C3","C2","C1","C0","D7","D6","D5","D4","D3","D2","D1","D0",
                             "E7","E6","E5","E4","E3","E2","E1","E0","F7","F6","F5","F4","F3","F2","F1","F0","G7","G6","G5","G4","G3","G2","G1","G0","H7","H6","H5","H4","H3","H2","H1","H0",
                             "I0", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "J0", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "K0", "K1", "K2", "K3", "K4", "K5", "K6", "K7", "L0", "L1", "L2", "L3", "L4", "L5", "L6", "L7", 
                             "M0", "M1", "M2", "M3", "M4", "M5", "M6", "M7", "N0", "N1", "N2", "N3", "N4", "N5", "N6", "N7", "O0", "O1", "O2", "O3", "O4", "O5", "O6", "O7", "P0", "P1", "P2", "P3", "P4", "P5", "P6", "P7");
    this.pinWidth = (this.width - this.paddingLR * 2) / 71;    //引脚宽度不应小于16
    this.pinHeight = 11;
    this.showName = true; //是否在芯片上显示芯片名称
    this.showBorder = true;//是否显示外框
    this.showPinNo = false;//是否显示引脚编号

    //i:引脚间距    [x,y]：除掉边距之外，以芯片左上角为[0,0]、右下角为[1,1]的相对坐标
    var i = 1 / 71;
    this.pinPosition = new Array([i * 0, 1], [i * 1, 1], [i * 2, 1], [i * 3, 1], [i * 4, 1], [i * 5, 1], [i * 6, 1], [i * 7, 1],
                                 [i * 9, 1], [i * 10, 1], [i * 11, 1], [i * 12, 1], [i * 13, 1], [i * 14, 1], [i * 15, 1], [i * 16, 1],
                                 [i * 18, 1], [i * 19, 1], [i * 20, 1], [i * 21, 1], [i * 22, 1], [i * 23, 1], [i * 24, 1], [i * 25, 1],
                                 [i * 27, 1], [i * 28, 1], [i * 29, 1], [i * 30, 1], [i * 31, 1], [i * 32, 1], [i * 33, 1], [i * 34, 1],
                                 [i * 36, 1], [i * 37, 1], [i * 38, 1], [i * 39, 1], [i * 40, 1], [i * 41, 1], [i * 42, 1], [i * 43, 1],
                                 [i * 45, 1], [i * 46, 1], [i * 47, 1], [i * 48, 1], [i * 49, 1], [i * 50, 1], [i * 51, 1], [i * 52, 1],
                                 [i * 54, 1], [i * 55, 1], [i * 56, 1], [i * 57, 1], [i * 58, 1], [i * 59, 1], [i * 60, 1], [i * 61, 1],
                                 [i * 63, 1], [i * 64, 1], [i * 65, 1], [i * 66, 1], [i * 67, 1], [i * 68, 1], [i * 69, 1], [i * 70, 1],
                                 [i * 70, 0], [i * 69, 0], [i * 68, 0], [i * 67, 0], [i * 66, 0], [i * 65, 0], [i * 64, 0], [i * 63, 0],
                                 [i * 61, 0], [i * 60, 0], [i * 59, 0], [i * 58, 0], [i * 57, 0], [i * 56, 0], [i * 55, 0], [i * 54, 0],
                                 [i * 52, 0], [i * 51, 0], [i * 50, 0], [i * 49, 0], [i * 48, 0], [i * 47, 0], [i * 46, 0], [i * 45, 0],
                                 [i * 43, 0], [i * 42, 0], [i * 41, 0], [i * 40, 0], [i * 39, 0], [i * 38, 0], [i * 37, 0], [i * 36, 0],
                                 [i * 34, 0], [i * 33, 0], [i * 32, 0], [i * 31, 0], [i * 30, 0], [i * 29, 0], [i * 28, 0], [i * 27, 0],
                                 [i * 25, 0], [i * 24, 0], [i * 23, 0], [i * 22, 0], [i * 21, 0], [i * 20, 0], [i * 19, 0], [i * 18, 0],
                                 [i * 16, 0], [i * 15, 0], [i * 14, 0], [i * 13, 0], [i * 12, 0], [i * 11, 0], [i * 10, 0], [i * 9, 0],
                                 [i * 7, 0], [i * 6, 0], [i * 5, 0], [i * 4, 0], [i * 3, 0], [i * 2, 0], [i * 1, 0], [i * 0, 0]);

    //引脚类型  0：输入  10:必要输入  1：输出  2：地  3：电源   4:其它  11：输入/输出
    this.pinFunction = new Array(11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
                                 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
                                 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
                                 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11);

    this.pinValue = new Array(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

    //引脚与其它引脚的连接线对象
    this.connection = new Array([], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [],
                                [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [],
                                [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [],
                                [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []);

    //输入总线的数据
    this.inputData =new Array(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

    this.inputCount=0; // 输入插座计数。在同一时刻，可能有多个插座向总线输入数据

    this.inputCurrent=-1; //当前输入插座的编号。-1表示无
    
    //插座输入数据的先后次序。此总线将最新输入作为实际输入，当最新输入断开时，以次新输入作为实际输入，以此类推。0表示此插座没有输入
    this.inputOrder=new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); 

};

//判断目前芯片是否已达到运算条件(是否所有的必要输入都已经有输入值)
CompoBUS.prototype.beReady = function () {
    for (var i = 0; i <= 127; i++) {
        if (this.pinValue[i] != 2) {
            return true;
        }
    };

    return false;
};

//设置输入引脚的值，并且判断目前芯片是否已达到运算条件 
CompoBUS.prototype.input = function (pinNo, value) {
    if (value == this.inputData[pinNo]) return false; //如果输入的值没有变化，则无需重新计算
    this.inputData[pinNo] = value;
    var n=Math.floor(pinNo/8);

    if (value != 2){  //如果有数据输入
        if (this.inputOrder[n]==0){  //如果是新插座
            this.inputCount=this.inputCount+1;
            this.inputCurrent=n;
            this.inputOrder[this.inputCurrent]=this.inputCount;             
        }else{
            if(n !=this.inputCurrent){// 如果是排在后面被屏蔽的插座
                for (var j=0;j<=15;j++){
                    if (this.inputOrder[j]>this.inputOrder[n])
                        this.inputOrder[j]=this.inputOrder[j]-1;
                };    
                this.inputOrder[n]=this.inputCount;
                this.inputCurrent=n;
            };
        };
    }else{  //如果有数据断开
        if(n ==this.inputCurrent){//如果是当前插座
            this.inputCount=this.inputCount-1;
            this.inputOrder[n]=0;
            if(this.inputCount==0){
                this.inputCurrent=-1;
            }else{    
                for (var j=0;j<=15;j++){
                    if (this.inputOrder[j]==this.inputCount)
                        this.inputCurrent=j;
                }; 
            };
        }else{
            if(this.inputOrder[n]!=0){// 如果是排在后面被屏蔽的插座
                this.inputCount=this.inputCount-1;
                for (var j=0;j<=15;j++){
                    if (this.inputOrder[j]>this.inputOrder[n])
                        this.inputOrder[j]=this.inputOrder[j]-1;
                };
                this.inputOrder[n]=0;
             };
        };

    };

    return true;

};

CompoBUS.prototype.work = function () {
    if(this.inputCount<=0){
        for (i = 0; i <= 127; i++)
             this.pinValue[i] =2;
        return;
    };

    for (i = 0; i <= 127; i++) {
        if (i <= 63) {
                if(this.inputCurrent<=7){   
                    this.pinValue[i] = this.inputData[this.inputCurrent*8+i% 8];
                }else{
                    this.pinValue[i] = this.inputData[this.inputCurrent*8+7-i% 8];
                };
        } else {
                if(this.inputCurrent<=7){   
                    this.pinValue[i] = this.inputData[this.inputCurrent*8+7-i% 8];
                }else{
                    this.pinValue[i] = this.inputData[this.inputCurrent*8+i% 8];
                };                
        };
    };
};

CompoBUS.prototype.reset = function () {
    this.pinValue = [2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2];

    this.inputData =new Array(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

    this.inputCount=0; 
    this.inputCurrent=-1;     
    this.inputOrder=new Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); 

};

