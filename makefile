TITLE = Zoo
CPP = Area.cpp
CPP += ElephantPit.cpp
CPP += FoodRoom.cpp
CPP += GorillaPit.cpp
CPP += ItemUsage.cpp
CPP += Layout.cpp
CPP += LionCage.cpp
CPP += MidPathway.cpp
CPP += NorthPathway.cpp
CPP += Outside.cpp
CPP += Player.cpp
CPP += SnakePit.cpp
CPP += SouthPathway.cpp
CPP += StartingRoom.cpp
CPP += ToolRoom.cpp
CPP += Zoo.cpp
CPP += Main.cpp

all:
	g++ ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
