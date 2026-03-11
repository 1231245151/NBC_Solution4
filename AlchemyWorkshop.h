#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "PotionRecipe.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop
{
private:
    vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const string& name, const vector<string>& ingredients)
    {
        recipes.push_back(PotionRecipe(name, ingredients));
        cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << endl;
    }

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const
    {
        if (recipes.empty())
        {
            cout << "아직 등록된 레시피가 없습니다." << endl;
            return;
        }

        cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
        for (size_t i = 0; i < recipes.size(); ++i)
        {
            recipes[i].displayRecipe();
        }
        cout << "---------------------------\n";
    }

    // 포션 이름 검색
    PotionRecipe SearchCopyRecipeByName(string _name)
    {
        PotionRecipe SearchRecipe;

        // 애초에 레시피잇어야 작동
        if (recipes.empty())
        {
            cout << "아직 등록된 레시피가 없습니다." << endl;
            return SearchRecipe;
        }

        bool search = false;

        // 배열을 앞에서부터 찾아간다(중복은 없다는 가정)
        for (vector<PotionRecipe>::iterator it = recipes.begin(); it != recipes.end(); ++it)
        {
            if (it->GetName() == _name)
            {
                SearchRecipe = (*it);
                cout << "해당 포션 레시피를 발견하였습니다. " << endl;
                SearchRecipe.displayRecipe();

                search = true;
                break;
            }
        }

        // 레시피가 없다면
        if(!search)
        {
            cout << "해당 포션 레시피는 존재하지 않습니다" << endl;
        }

        //레시피가 발견되었다면 해당 레시피 반환
        return SearchRecipe;
    }


    // 포션 재료 검색
    vector<PotionRecipe> SearchCopyRecipeByingred(string _name)
    {
        // 발견된 레시피 전부 보낼것이기에 배열로 설정
        vector<PotionRecipe> SearchRecipes;

        // 애초에 레시피잇어야 작동
        if (recipes.empty())
        {
            cout << "아직 등록된 레시피가 없습니다." << endl;
            return SearchRecipes;
        }

        // 배열을 앞에서부터 찾아간다
        for (const PotionRecipe& it : recipes)
        {
            const vector<string>& ingredients = it.Getingredients();

            //재료검색
            for (const string& stringit : ingredients)
            {
                // 해당재료가진 레시피 발견햇으면 해당레시피로 저장후 나오기
                if (stringit == _name)
                {
                    SearchRecipes.push_back(it);
                    it.displayRecipe();
                    break;
                }
            }

        }

        if(SearchRecipes.empty())
            cout << "해당 재료를 가진 레시피는 존재하지않습니다." << endl;

        return SearchRecipes;
    }

};