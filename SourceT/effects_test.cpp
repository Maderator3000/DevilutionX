#include <gtest/gtest.h>
#include "devilution.h"

TEST(Drlg_l4, calc_snd_position_center) {
	dvl::plr[dvl::myplr].WorldX = 50;
	dvl::plr[dvl::myplr].WorldY = 50;
	int plVolume = 0;
	int plPan = 0;
	EXPECT_EQ(dvl::calc_snd_position(50, 50, &plVolume, &plPan), true);
	EXPECT_EQ(plVolume, 0);
	EXPECT_EQ(plPan, 0);
}

TEST(Drlg_l4, calc_snd_position_near) {
	dvl::plr[dvl::myplr].WorldX = 50;
	dvl::plr[dvl::myplr].WorldY = 50;
	int plVolume = 0;
	int plPan = 0;
	EXPECT_EQ(dvl::calc_snd_position(55, 50, &plVolume, &plPan), true);
	EXPECT_EQ(plVolume, -320);
	EXPECT_EQ(plPan, 1280);
}

TEST(Drlg_l4, calc_snd_position_out_of_range) {
	dvl::plr[dvl::myplr].WorldX = 12;
	dvl::plr[dvl::myplr].WorldY = 12;
	int plVolume = 0;
	int plPan = 0;
	EXPECT_EQ(dvl::calc_snd_position(112, 112, &plVolume, &plPan), false);
	ASSERT_GE(plVolume, 6400);
	EXPECT_EQ(plPan, 0);
}

TEST(Drlg_l4, calc_snd_position_extream_right) {
	dvl::plr[dvl::myplr].WorldX = 50;
	dvl::plr[dvl::myplr].WorldY = 50;
	int plVolume = 0;
	int plPan = 0;
	EXPECT_EQ(dvl::calc_snd_position(76, 50, &plVolume, &plPan), false);
	EXPECT_EQ(plVolume, 0);
	EXPECT_GT(plPan, 6400);
}

TEST(Drlg_l4, calc_snd_position_extream_left) {
	dvl::plr[dvl::myplr].WorldX = 50;
	dvl::plr[dvl::myplr].WorldY = 50;
	int plVolume = 0;
	int plPan = 0;
	EXPECT_EQ(dvl::calc_snd_position(24, 50, &plVolume, &plPan), false);
	EXPECT_EQ(plVolume, 0);
	EXPECT_LT(plPan, -6400);
}
