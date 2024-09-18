#pragma once

class Settings {
public:
	static Settings& Instance() {
		static Settings instance;
		return instance;
	}

	unsigned int getWidth() const { return m_width; }
	unsigned int getHeight() const { return m_height; }

	void setWidth(unsigned int width) { m_width = width; }
	void setHeight(unsigned int height) { m_height = height; }

private:
	Settings(unsigned int width = 1024, unsigned int height = 1920)
		: m_width(width), m_height(height) {};

	Settings(const Settings&) = delete;
	Settings& operator=(const Settings&) = delete;



	unsigned int m_width;
	unsigned int m_height;
};