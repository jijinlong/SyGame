#pragma once
/**
 * theNet.bind(msgId,this);
 * theNet.doCmd()
 * {
 *		objects = findObject(msgId);
 *		theDispatcher.handle(object,cmd,cmdSize);
 * }
 */

// TODO 负责不间断短连接
// TODO 负责接收消息到缓存
// TODO 在逻辑主循环里分发事件
// TODO 负责发送消息
// 发送 与接收消息在一个线程里