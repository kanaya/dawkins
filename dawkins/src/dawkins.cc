#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

const int len_string = 28;
const int n_charset = 27;
const int mutation_ratio = 100;

class random_string {
	private:
	std::vector<int> cs;
	int v;

	void randomize(std::default_random_engine engine) {
		std::uniform_int_distribution<> dist(0, n_charset);
		for (int i = 0; i < len_string; ++i) {
			cs[i] = dist(engine);
		}
		evaluate();
	}

	void evaluate() {
		v = std::accumulate(cs.begin(), cs.end(), 0);
	}

	public:
	random_string(std::default_random_engine engine): cs(len_string), v(0) {
		randomize(engine);
	}

	int value() const {
		return v;
	}

	void mutation(std::default_random_engine engine) {
		std::uniform_int_distribution<> dist1(0, n_charset);
		std::uniform_int_distribution<> dist2(0, len_string);
		cs[dist2(engine)] = dist1(engine);
		evaluate();
	}

	std::ostream &put(std::ostream &os) const {
		for (int i = 0; i < len_string - 1; ++i) {
			os << cs[i] << ' ';
		}
		os << cs[len_string - 1];
		return os;
	}
};

std::ostream &operator <<(std::ostream &os, const random_string &rs) {
	return rs.put(os);
}

int main() {
	const int n = 100;
	std::random_device seed_gen;
	std::vector<random_string *> rs{n};
	for (auto &r: rs) {
		std::default_random_engine engine{seed_gen()};
		r = new random_string{engine};
	}
	for (int gen = 0; gen < 100; ++gen) {
		std::sort(rs.begin(), rs.end(), [](random_string *x, random_string *y) { return x->value() < y->value(); });
		std::cout << "[" << rs[0]->value() << "]" << std::endl;
		for (int i = 1; i < n; ++i) {
			std::default_random_engine engine{seed_gen()};
			*rs[i] = *rs[0];
			rs[i]->mutation(engine);
		}
	}
	for (auto r: rs) {
		delete r;
	}
	return 0;
}