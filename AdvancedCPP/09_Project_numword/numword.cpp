#include "numword.h"

namespace bw {

// Assignment operator
numword& numword::operator=(const numnum& num) {
    setnum(num);
    return *this;
}

const string& numword::words() {
    return words(_num);
}

// Convert to words
const string& numword::words(const numnum& num) {
    numnum n{ num };
    clearbuf();

    if (n > maxnum) {
        appendbuf(errnum);
        return *_buf;
    }

    if (n == 0) {
        appendbuf(_singles[n]);
        return *_buf;
    }

    // Powers of 1000
    if (n >= thousand) {
        for (auto i = five_i; i > zero_i; --i) {
            numnum power {pow_i(thousand, i)};
            numnum chunk {(n - (n % power)) / power};
            if (chunk) {
                numword nw {chunk};
                appendbuf(nw.words());
                appendbuf(_powers[i]);
                n -= chunk * power;
            }
        }
    }
    // Hundreds
    if (n >= hundred && n < thousand) {
        numnum chunk {(n - (n % hundred)) / hundred};
        numword nw {chunk};
        appendbuf(nw.words());
        appendbuf(_hundred_string);
        n -= chunk * hundred;
    }
    // Tens
    if (n >= twenty && n < hundred) {
        numnum chunk {(n - (n % ten)) / ten};
        appendbuf(_tens[chunk]);
        n -= chunk * ten;
        _hyphen_flag = true;
    }
    // Teens
    if (n >= ten && n < twenty) {
        appendbuf(_teens[n - ten]);
        n = zero;
    }
    // Singles
    if (n > zero && n < ten) {
        appendbuf(_singles[n]);
    }

    return *_buf;
}

// MARK: - Private Methods

// Reset the buffer
void numword::clearbuf() {
    *_buf = string {};
}

// Append text to the string buffer
void numword::appendbuf(const string& s) {
    appendspace();
    _buf->append(s);
}

void numword::appendbuf(const string_view& s) {
    appendspace();
    _buf->append(s.data(), s.size());
}

void numword::appendbuf(const char c) {
    _buf->append(1, c);
}

// Append space (or hyphen)
void numword::appendspace() {
    if (bufsize()) {
        appendbuf(_hyphen_flag ? _hyphen : _space);
        _hyphen_flag = false;
    }
}

numnum numword::pow_i(const numnum base, numnum exp) {
    numnum result {1};
    while (exp--) result *= base;
    return result;
}

// Add the bufsize() definition
size_t numword::bufsize() const {
    return _buf->size();
}

} // namespace bw
