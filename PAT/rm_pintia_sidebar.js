// pintia 左侧的 sidebar 无法收起, 题目区太小了, 可以把下面的代码粘到 Console , 从而把 sidebar 去掉

var container = document.getElementsByClassName("container_3-707 container")[0];
container.style.paddingLeft = "0px";

var sidebar = document.getElementsByClassName("sidebar_3aAZX")[0];
sidebar.remove();

var sidebarBG = document.getElementsByClassName("sidebarBackground_1dI8r")[0];
sidebarBG.remove();
