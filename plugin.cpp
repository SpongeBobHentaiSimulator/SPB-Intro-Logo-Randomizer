#include <RE/Skyrim.h>

#include <filesystem>
#include <fstream>
#include <random>
#include <vector>

namespace fs = std::filesystem;

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
	SKSE::Init(skse);

	const fs::path sourceDir = "Data/Video/SPBIntroLogos";
	const fs::path targetFile = "Data/Video/BGS_Logo.bik";

	try {
		// Ensure the custom logo directory exists
		if (!fs::exists(sourceDir)) {
			fs::create_directories(sourceDir);
			return true;
		}

		// Collect all .bik files from the source directory
		std::vector<fs::path> bikFiles;
		for (const auto& entry : fs::directory_iterator(sourceDir))
			if (entry.is_regular_file() && entry.path().extension() == ".bik")
				bikFiles.push_back(entry.path());

		// Randomly select and copy one file to the target path
		if (!bikFiles.empty()) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<size_t> dist(0, bikFiles.size() - 1);
			fs::path chosenLogo = bikFiles[dist(gen)];
			fs::copy_file(chosenLogo, targetFile, fs::copy_options::overwrite_existing);
		}
	} catch (const fs::filesystem_error&) {
		// Fail silently to ensure the game remains stable
	}
	return true;
}