set_project("SPBIntroLogoRandomizer")
set_version("2.0.0")

set_languages("c++23")
set_arch("x64")

-- Dependencias
includes("extern/CommonLibSSE-NG")

target("SPBIntroLogoRandomizer")
	set_kind("shared")
	
	-- Prevenir macros min/max de Windows
	add_defines("NOMINMAX")

	set_pcxxheader("src/PCH.h")
	
	add_deps("commonlibsse-ng")
	add_rules("commonlibsse-ng.plugin", {
		name = "SPBIntroLogoRandomizer",
		author = "SpongeBobHentaiSimulator",
		description = "I did this to load hentai intros"
	})

	add_files("src/**.cpp")