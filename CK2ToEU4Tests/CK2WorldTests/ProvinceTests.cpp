#include "gtest/gtest.h"
#include "../CK2ToEU4/Source/CK2World/Provinces/Province.h"
#include <sstream>

TEST(CK2World_ProvinceTests, IDCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getID(), 42);
}

TEST(CK2World_ProvinceTests, cultureCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tculture=\"paradoxian\"";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getCulture(), "paradoxian");
}

TEST(CK2World_ProvinceTests, cultureDefaultsToBlank)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getCulture(), "");
}

TEST(CK2World_ProvinceTests, religionCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\treligion=\"paradoxian\"";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getReligion(), "paradoxian");
}

TEST(CK2World_ProvinceTests, religionDefaultsToBlank)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getReligion(), "");
}

TEST(CK2World_ProvinceTests, nameCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tname=\"paradoxian\"";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getName(), "paradoxian");
}

TEST(CK2World_ProvinceTests, nameDefaultsToBlank)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getName(), "");
}

TEST(CK2World_ProvinceTests, primarySettlementCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tprimary_settlement=\"b_paradox\"";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getPrimarySettlement(), "b_paradox");
}

TEST(CK2World_ProvinceTests, primarySettlementDefaultsToBlank)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getPrimarySettlement(), "");
}

TEST(CK2World_ProvinceTests, maxSettlementsCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tmax_settlements=7";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getMaxSettlements(), 7);
}

TEST(CK2World_ProvinceTests, maxSettlementsDefaultToZero)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getMaxSettlements(), 0);
}

TEST(CK2World_ProvinceTests, baronyCanBeLoaded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "b_test-baronY_name3={}\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getBaronyCount(), 1);
}

TEST(CK2World_ProvinceTests, baronyNameCanBeLoaded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "b_test-baronY_name3={}\n";
	input << "}";

	const CK2::Province theProvince(input, 42);
	const auto& baronies = theProvince.getBaronies();
	const auto& baronyItr = baronies.begin();
	
	ASSERT_EQ(baronyItr->second.getName(), "b_test-baronY_name3");
	ASSERT_EQ(baronyItr->second.getName(), baronyItr->first);
}

TEST(CK2World_ProvinceTests, multipleBaroniesCanBeLoaded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "b_test-baronY_name3={}\n";
	input << "b_test-BaronY_name2={}\n";
	input << "b_test-baronY_namE1={}\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getBaronyCount(), 3);
}

TEST(CK2World_ProvinceTests, baronyWeightsCanBeAdded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "b_test-baronY_name3={ca_town=yes tp_city=yes}\n";
	input << "b_test-BaronY_name2={tp_building=yes}\n";
	input << "b_test-baronY_namE1={ct_skyscraper=yes}\n";
	input << "}";

	const CK2::Province theProvince(input, 42);

	ASSERT_EQ(theProvince.getBuildingWeight(), 13);
}
