#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate the cosine similarity between two vectors
double cosineSimilarity(const vector<double>& vec1, const vector<double>& vec2) {
    double dotProduct = 0.0, normVec1 = 0.0, normVec2 = 0.0;

    for (size_t i = 0; i < vec1.size(); i++) {
        dotProduct += vec1[i] * vec2[i];
        normVec1 += vec1[i] * vec1[i];
        normVec2 += vec2[i] * vec2[i];
    }

    normVec1 = sqrt(normVec1);
    normVec2 = sqrt(normVec2);

    if (normVec1 == 0 || normVec2 == 0) return 0.0;

    return dotProduct / (normVec1 * normVec2);
}

void recommend(const vector<vector<double>>& itemData, const vector<double>& userPreferences) {
    double maxSimilarity = -1.0;
    int recommendedItem = -1;

    for (size_t i = 0; i < itemData.size(); i++) {
        double similarity = cosineSimilarity(itemData[i], userPreferences);
        cout << "Similarity with Item " << i + 1 << ": " << similarity << endl;

        if (similarity > maxSimilarity) {
            maxSimilarity = similarity;
            recommendedItem = i;
        }
    }

    if (recommendedItem != -1) {
        cout << "Recommended Item: Item " << recommendedItem + 1 << endl;
    } else {
        cout << "No suitable recommendation found." << endl;
    }
}

int main() {
    // Define item data (e.g., features of items)
    vector<vector<double>> itemData = {
        {1.0, 0.0, 3.0}, // Item 1
        {0.0, 2.0, 1.0}, // Item 2
        {1.0, 1.0, 2.0}  // Item 3
    };

    // User preferences (e.g., user's feature importance)
    vector<double> userPreferences = {1.0, 1.0, 3.0};

    cout << "Calculating recommendations..." << endl;
    recommend(itemData, userPreferences);

    return 0;
}
