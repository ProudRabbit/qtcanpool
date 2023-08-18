﻿/**
 * Copyleft (C) 2023 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
**/
#include "QxRibbonFactory.h"
#include "QxRibbonControls.h"

QX_BEGIN_NAMESPACE

RibbonFactory::RibbonFactory()
    : m_opt(new RibbonStyleOption())
{
}

RibbonFactory::~RibbonFactory()
{
}

RibbonControlButton *RibbonFactory::createHideGroupButton(QWidget *parent)
{
    RibbonControlButton *btn = new RibbonControlButton(parent);
    btn->setAutoRaise(false);
    btn->setObjectName(QStringLiteral("RibbonBarHideGroupButton"));
    btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    return btn;
}

RibbonStyleOption &RibbonFactory::getRibbonStyleOption()
{
    return *m_opt;
}

void RibbonFactory::setRibbonStyleOption(RibbonStyleOption *opt)
{
    m_opt.reset(opt);
}

QX_END_NAMESPACE
